#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../include/TXTUserPersistenceListService.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	TXTUserPersistenceListService::TXTUserPersistenceListService() : PersistenceListService(), mFileName("leaderboard.txt")
	{
		// Prüfen, ob die Datei bereits existiert
		if (!std::filesystem::exists(mFileName))
		{
			// Erstelle eine neue Datei für die Bestenliste.
			std::ofstream stream(mFileName, std::ios_base::app);
			stream.close();
		}
	}

	TXTUserPersistenceListService::~TXTUserPersistenceListService()
	{
	}
	/**
	* @brief Speichert die Bestenliste in die Datenbank.
	*
	* @param Speichert die Liste in der Datei
	*/
	void TXTUserPersistenceListService::pushList(const std::vector<User>& list)
	{

		mList = list;
		std::ofstream stream(mFileName, std::ios_base::trunc);

		for (const auto& item : mList) {
			std::string line;
			std::stringstream ss;

			// String für die Datenbank bauen
			// Carry return sorgt beim einlesen für einen weiteren durchlauf, wird jedoch durch die Abfrage des Inhalts abgebrochen.
			ss << std::to_string(item.Date) << "," << item.Name << "," << std::to_string(item.Tries) << "\n";
			line = ss.str();

			stream.write(line.c_str(), line.size());
		}
		stream.close();
	}

	/**
	* @brief Liest die aktuelle Leaderboarddatei ein.
	*/
	std::vector<User>& TXTUserPersistenceListService::getList()
	{
		std::ifstream stream(mFileName, std::ios_base::in);
		std::string line;

		// Solange das Ende der Datei nicht erreicht ist, nächste Zeile einlesen
		while (!stream.eof()) {
			// Spaltenseperatur [,] Zeilenseperator ['/n']
			// Zeilenkonvention Datum, Name, Versuchsanzahl
			std::getline(stream, line);

			// Prüfe, ob Daten vorhanden sind, ansonsten break:
			if (line.empty()) {
				break;
			}

			// Spalten aus dem Zeilenstring parsen
			// 1. Spalte Datum
			User temp;
			std::size_t first = 0;
			// suche Spaltenseperatur für 1. Spalte
			std::size_t found = line.find_first_of(",");

			std::string strNumber = line.substr(first, found);
			auto intNumber = Utilities::ParseStringToInt(strNumber);

			// Zeitfeld von String in int parsen, bei Fehler Exception auslösen.
			if (!intNumber) {
				throw std::runtime_error("ERROR: Parsen der Datenbank fehlgeschlagen [Datum stimmt nicht].");
			}

			temp.Date = static_cast<std::time_t>(*intNumber);

			// + 1 um das Komma zu überspringen und zum ersten Char der neuen Spalte zu springen
			first = found + 1;

			// 2. Spalte Name
			found = line.find_first_of(",", first);
			temp.Name = line.substr(first, found - first);

			// + 1 um das Komma zu überspringen und zum ersten Char der neuen Spalte zu springen
			first = found + 1;

			// 3. Spalte Anzahl der Versuche
			strNumber = line.substr(first, found - first);

			intNumber = Utilities::ParseStringToInt(strNumber);

			// Anzahl der Versuche von String in in int parsen, bei Fehler Exception auslösen.
			if (!intNumber) {
				throw std::runtime_error("ERROR: Parsen der Datenbank fehlgeschlagen.");
			}

			temp.Tries = *intNumber;

			// geparster User in die Highscoreliste eintragen
			mList.push_back(temp);
		}
		stream.close();

		// Auf eine Sortierung wird verzichtet. Die Datei darf nicht manuell bearbeitet werden. Daher muss auch die Reihenfolge stimmen.

		return mList;
	}

	/**
	* @brief Löscht die gesamte Bestenliste.
	*/
	void TXTUserPersistenceListService::clear()
	{
		mList.clear();
		std::ofstream stream(mFileName, std::ios_base::trunc);
		stream.close();
	}
}
