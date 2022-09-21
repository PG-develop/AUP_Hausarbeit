#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../include/TXTUserPersistenceListService.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Pr�ft, ob die Datei f�r die Datenspeicherung bereits existiert.
	* Wenn nicht, wird eine Datei erstellt.
	*/
	TXTUserPersistenceListService::TXTUserPersistenceListService() : PersistenceListService(), mFileName("leaderboard.txt")
	{
		// Pr�fen, ob die Datei bereits existiert
		if (!std::filesystem::exists(mFileName))
		{
			// Erstelle eine neue Datei f�r die Bestenliste.
			std::ofstream stream(mFileName, std::ios_base::app);
			stream.close();
		}
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	TXTUserPersistenceListService::~TXTUserPersistenceListService()
	{
	}

	/**
	* @brief Speichert die Bestenliste in die Datenbank.
	*
	* @param [list_p] const std::vector<User> Speichert die Liste in der Datei
	*/
	void TXTUserPersistenceListService::PushList(const std::vector<User>& list_p)
	{
		// Speichere Liste im Service ab
		mList = list_p;

		// �ffne Datei, die Liste wird immer beim �ffnen gel�scht und mit der neuen Liste �berschrieben
		std::ofstream stream(mFileName, std::ios_base::trunc);

		// gehe alle Listenelemente durch
		for (const auto& item : mList) {
			std::string line;
			std::stringstream ss;

			// String f�r die Datenbank bauen
			// Carry return sorgt beim einlesen f�r einen weiteren durchlauf, wird jedoch durch die Abfrage des Inhalts abgebrochen.
			ss << std::to_string(item.Date) << "," << item.Name << "," << std::to_string(item.Tries) << "\n";
			line = ss.str();

			// In die Datei schreiben
			stream.write(line.c_str(), line.size());
		}
		stream.close();
	}

	/**
	* @brief Liest die aktuelle Leaderboarddatei ein.
	* 
	* @return std::vector<User> Referenz auf die aktuelle Liste
	*/
	std::vector<User>& TXTUserPersistenceListService::GetList()
	{
		std::ifstream stream(mFileName, std::ios_base::in);
		std::string line;

		// Solange das Ende der Datei nicht erreicht ist, n�chste Zeile einlesen
		while (!stream.eof()) {
			// Spaltenseperatur [,] Zeilenseperator ['/n']
			// Zeilenkonvention Datum, Name, Versuchsanzahl
			std::getline(stream, line);

			// Pr�fe, ob Daten vorhanden sind, ansonsten break:
			if (line.empty()) {
				break;
			}

			// Spalten aus dem Zeilenstring parsen
			// 1. Spalte Datum
			User temp;
			std::size_t first = 0;
			// suche Spaltenseperatur f�r 1. Spalte
			std::size_t found = line.find_first_of(",");

			std::string strNumber = line.substr(first, found);
			auto intNumber = Utilities::ParseStringToInt(strNumber);

			// Zeitfeld von String in int parsen, bei Fehler Exception ausl�sen.
			if (!intNumber) {
				throw std::runtime_error("ERROR: Parsen der Datenbank fehlgeschlagen [Datum stimmt nicht].");
			}

			temp.Date = static_cast<std::time_t>(*intNumber);

			// + 1 um das Komma zu �berspringen und zum ersten Char der neuen Spalte zu springen
			first = found + 1;

			// 2. Spalte Name
			found = line.find_first_of(",", first);
			temp.Name = line.substr(first, found - first);

			// + 1 um das Komma zu �berspringen und zum ersten Char der neuen Spalte zu springen
			first = found + 1;

			// 3. Spalte Anzahl der Versuche
			strNumber = line.substr(first, found - first);

			intNumber = Utilities::ParseStringToInt(strNumber);

			// Anzahl der Versuche von String in in int parsen, bei Fehler Exception ausl�sen.
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
	* @brief L�scht die gesamte Bestenliste.
	*/
	void TXTUserPersistenceListService::Clear()
	{
		mList.clear();
		std::ofstream stream(mFileName, std::ios_base::trunc);
		stream.close();
	}
}
