#include <filesystem>
#include <fstream>
#include <sstream>

#include "../include/TXTSetupPersistenceListService.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	TXTSetupPersistenceListService::TXTSetupPersistenceListService() 
		: PersistenceListService()
		, mFileName("setup.txt")
	{
		// Pr�fen, ob die Datei bereits existiert
		if (!std::filesystem::exists(mFileName))
		{
			// Erstelle eine neue Datei f�r die Bestenliste.
			std::ofstream stream(mFileName, std::ios_base::app);
			stream.close();
		}
	}

	TXTSetupPersistenceListService::~TXTSetupPersistenceListService()
	{
	}

	/**
	* @brief Datensatz speichern
	* 
	* Der Datensatz wird in einem String vorbereitet und in die Datei setup.txt gespeichert.
	* 
	* @param [list] const std::vector<Setup>& zu speichernde Liste
	*/
	void TXTSetupPersistenceListService::pushList(const std::vector<Setup>& list)
	{
		mList = list;
		std::ofstream stream(mFileName, std::ios_base::trunc);

		// alle Listenelemente durchgehen und speichern
		for (const auto& item : mList) {
			std::stringstream ss;

			// String f�r die Datenbank bauen
			// Carry return sorgt beim einlesen f�r einen weiteren durchlauf, wird jedoch durch die Abfrage des Inhalts abgebrochen.
			ss << std::to_string(item.AmmountOfChoices) << "," << std::to_string(item.MaxRange) << "\n";
			
			// Datensatz in die Datei schreiben
			stream.write(ss.str().c_str(), ss.str().size());
		}

		// Filestream schlie�en
		stream.close();
	}

	std::vector<Setup>& TXTSetupPersistenceListService::getList()
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
			Setup temp;
			std::size_t first = 0;
			// suche Spaltenseperatur f�r 1. Spalte
			std::size_t found = line.find_first_of(",");

			std::string strNumber = line.substr(first, found);
			auto intNumber = Utilities::ParseStringToInt(strNumber);

			// Zeitfeld von String in int parsen, bei Fehler Exception ausl�sen.
			if (!intNumber) {
				throw std::runtime_error("ERROR: Parsen der Datenbank fehlgeschlagen [Datum stimmt nicht].");
			}

			temp.AmmountOfChoices = static_cast<std::time_t>(*intNumber);

			// + 1 um das Komma zu �berspringen und zum ersten Char der neuen Spalte zu springen
			first = found + 1;

			// 3. Spalte Anzahl der Versuche
			strNumber = line.substr(first, found - first);

			intNumber = Utilities::ParseStringToInt(strNumber);

			// Anzahl der Versuche von String in in int parsen, bei Fehler Exception ausl�sen.
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
	* @brief L�scht die Einstellungen
	*		 Wird nicht ben�tigt und daher nicht implementiert
	*		 Kann eventuell f�r das Zur�cksetzen auf Werkseinstellungen benutzt werden.
	*/
	void TXTSetupPersistenceListService::clear()
	{
		// Ausl�sung einer Exception, falls Funktion benutzt werden sollte.
		throw std::logic_error("function not yet implemented!");
	}
}