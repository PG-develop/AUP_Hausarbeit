#include <iostream>
#include <iomanip>
#include <conio.h>

#include "../include/LeaderboardState.hpp"
#include "../include/TXTUserPersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Instanziierung des UserRepositories
	* 
	* @param [stateManager] StateManager Referenz auf seinen StateManager
	*/
	LeaderboardState::LeaderboardState(StateManager& stateManager) : State(stateManager)
	{
		mUserRepository = std::make_unique<UserRepository>();
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	LeaderboardState::~LeaderboardState()
	{
	}

	/**
	* @brief Anzeige des States
	* 
	* Gibt die Bestenliste aus
	*/
	void LeaderboardState::Render()
	{
		//TODO: Wenn keine Benutzer in der Bestenliste gespeichert sind, nur ein Hinweis ausgeben.
		// 
		// Kopf
		std::cout << "+----------------------------------------------------+" << std::endl;
		std::cout << "|                     Bestenliste                    |" << std::endl;
		std::cout << "+----+-------------------+------------------+--------+" << std::endl;
		std::cout << "|    |       Datum       |       Name       |Versuche|" << std::endl;
		std::cout << "+----+-------------------+------------------+--------+" << std::endl;

		// Zähler für die Platzierungen
		int i = 0;

		// Gehe alle gespeicherten Benutzer in des Datensatzes durch:
		for (const User& user : mUserRepository->GetUserSortedByRang()) {

			// Zeit parsen
			std::tm* date = new tm();
			char buffer[128];

			localtime_s(date, &user.Date);
			strftime(buffer, sizeof(buffer), "%d.%m.%Y  %R", date);

			// Ausgabe der Zeile
			std::cout << "|" << std::setw(3) << ++i << " | " << buffer << " | " << std::setw(16) << user.Name << " | " << std::setw(6) << user.Tries << " |" << std::endl;
		}

		// Fusszeile
		std::cout << "+----+-------------------+------------------+--------+" << std::endl << std::endl;
		std::cout << "Zurueck mit einer Taste";
	}

	/**
	* @brief Benutzereingabe
	*/
	void LeaderboardState::ProcessEvents()
	{
		// Wartet so lange, bis der Benutzer eine Taste gedrückt hat.
		while (!_kbhit());
		_getch();
	}

	/**
	* @brief Ausführung der Statelogic
	*/
	void LeaderboardState::Update()
	{
		// Wechsel zurück zum MainState
		requestChange(States::MAIN);
	}
}