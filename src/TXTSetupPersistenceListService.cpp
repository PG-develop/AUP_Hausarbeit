#include <filesystem>
#include <fstream>
#include <sstream>

#include "../include/TXTSetupPersistenceListService.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Pr?ft, ob die Datei f?r die Datenspeicherung bereits existiert.
	* Wenn nicht, wird eine Datei erstellt.
	*/
	TXTSetupPersistenceListService::TXTSetupPersistenceListService() 
		: PersistenceListService()
		, mFileName("setup.txt")
	{
		// Pr?fen, ob die Datei bereits existiert
		if (!std::filesystem::exists(mFileName))
		{
			// Erstelle eine neue Datei f?r die Bestenliste.
			std::ofstream stream(mFileName, std::ios_base::app);
			stream.close();
		}
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	TXTSetupPersistenceListService::~TXTSetupPersistenceListService()
	{
	}

	/**
	* @brief Datensatz speichern
	* 
	* Der Datensatz wird in einem String vorbereitet und in die Datei setup.txt gespeichert.
	* 
	* @param [list_p] const std::vector<Setup>& zu speichernde Liste
	*/
	void TXTSetupPersistenceListService::PushList(const std::vector<Setup>& list_p)
	{
		// Speichere Liste im Service ab
		mList = list_p;

		// ?ffne Datei, die Liste wird immer beim ?ffnen gel?scht und mit der neuen Liste ?berschrieben
		std::ofstream stream(mFileName, std::ios_base::trunc);

		// alle Listenelemente durchgehen und speichern
		for (const auto& item : mList) {
			std::stringstream ss;

			// String f?r die Datenbank bauen
			// Carry return sorgt beim einlesen f?r einen weiteren durchlauf, wird jedoch durch die Abfrage des Inhalts abgebrochen.
			ss << std::to_string(item.AmmountOfChoices) << "," << std::to_string(item.MaxRange) << "\n";
			
			// Datensatz in die Datei schreiben
			stream.write(ss.str().c_str(), ss.str().size());
		}

		// Filestream schlie?en
		stream.close();
	}

	/**
	* @brief Liest die aktuelle Leaderboarddatei ein.
	*
	* @return std::vector<Setup> Referenz auf die aktuelle Liste
	*/
	std::vector<Setup>& TXTSetupPersistenceListService::GetList()
	{
		std::ifstream stream(mFileName, std::ios_base::in);
		std::string line;

		// Solange das Ende der Datei nicht erreicht ist, n?chste Zeile einlesen
		while (!stream.eof()) {
			// Spaltenseperatur [,] Zeilenseperator ['/n']
			// Zeilenkonvention Datum, Name, Versuchsanzahl
			std::getline(stream, line);

			// Pr?fe, ob Daten vorhanden sind, ansonsten break:
			if (line.empty()) {
				break;
			}

			// Spalten aus dem Zeilenstring parsen
			// 1. Spalte Versuchsanzahl
			Setup temp;
			std::size_t first = 0;
			// suche Spaltenseperatur f?r 1. Spalte
			std::size_t found = line.find_first_of(",");

			std::string strNumber = line.substr(first, found);
			auto intNumber = Utilities::ParseStringToInt(strNumber);

			// Zeitfeld von String in int parsen, bei Fehler Exception ausl?sen.
			if (!intNumber) {
				throw std::runtime_error("ERROR: Parsen der Datenbank fehlgeschlagen [Datum stimmt nicht].");
			}

			temp.AmmountOfChoices = static_cast<std::time_t>(*intNumber);

			// + 1 um das Komma zu ?berspringen und zum ersten Char der neuen Spalte zu springen
			first = found + 1;

			// 2. Spalte Streureichweite
			strNumber = line.substr(first, found - first);

			intNumber = Utilities::ParseStringToInt(strNumber);

			// Anzahl der Versuche von String in in int parsen, bei Fehler Exception ausl?sen.
			if (!intNumber) {
				throw std::runtime_error("ERROR: Parsen der Datenbank fehlgeschlagen.");
			}

			temp.MaxRange = *intNumber;

			// geparster Setup in die Liste eintragen
			mList.push_back(temp);
		}
		stream.close();

		return mList;
	}

	/**
	* @brief L?scht die Einstellungen
	*		 Wird nicht ben?tigt und daher nicht implementiert
	*		 Kann eventuell f?r das Zur?cksetzen auf Werkseinstellungen benutzt werden.
	*/
	void TXTSetupPersistenceListService::Clear()
	{
		// Ausl?sung einer Exception, falls Funktion benutzt werden sollte.
		throw std::logic_error("function not yet implemented!");
	}
}