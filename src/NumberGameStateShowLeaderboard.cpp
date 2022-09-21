#include <conio.h>
#include <iostream>
#include <iomanip>

#include "../include/NumberGameStateShowLeaderboard.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der Übergangsbedingungen: I
	*/
	NumberGameStateShowLeaderboard::NumberGameStateShowLeaderboard(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
	{
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::I));
		
		// Referenz auf das UserRepository speichern
		mUserRepository = &manager_p.GetUserRepository();
	}

	/**
	* @Destruktor
	*
	* Keine Funktion
	*/
	NumberGameStateShowLeaderboard::~NumberGameStateShowLeaderboard()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Anzeige der aktuellen Bestenliste
	* Der Benutzer wird aufgefordert, eine beliebige Taste zu drücken.
	*/
	void NumberGameStateShowLeaderboard::Render()
	{
		// Kopf
		std::cout << "Gesuchte Zahl: " << mGame->GetSearchedNumber() << std::endl;
		std::cout << "+----------------------------------------------------+" << std::endl;
		std::cout << "|                     Bestenliste                    |" << std::endl;
		std::cout << "+----+-------------------+------------------+--------+" << std::endl;
		std::cout << "|    |       Datum       |       Name       |Versuche|" << std::endl;
		std::cout << "+----+-------------------+------------------+--------+" << std::endl;

		// Platzierungsvariable
		int i = 0;

		for (const User& user : mUserRepository->GetUserSortedByRang()) {
			// Zeit parsen
			std::tm* date = new tm();
			char buffer[128];

			localtime_s(date, &user.Date);
			strftime(buffer, sizeof(buffer), "%d.%m.%Y  %R", date);

			std::cout << "|" << std::setw(3) << ++i << " | " << buffer << " | " << std::setw(16) << user.Name << " | " << std::setw(6) << user.Tries << " |" << std::endl;

			// Wenn die Zeit des im aktuellen Spiels gleich der Zeit in der Datenbank ist, dann makiere diesen Benutzer
			if (mGame->GetUser().Date == user.Date)
			{
				std::cout << "|" << std::setw(5) << "|" << std::setw(20) << "|" << std::setw(19) << std::setfill('=') << "|" << std::setfill(' ') << std::setw(9) << "|" << std::endl;
			}
		}

		std::cout << "+----+-------------------+------------------+--------+" << std::endl << std::endl;


		std::cout << "Weiter mit einer beliebigen Taste...";
	}

	/**
	* @brief Benutzereingabe
	* 
	* Ohne Funktion
	*/
	void NumberGameStateShowLeaderboard::ProcessEvents()
	{
	}

	/**
	* @brief Ausführung der Logik
	*
	* Es werden nur die Übergangsbedingungen geprüft
	*/
	void NumberGameStateShowLeaderboard::Update()
	{
		checkTransitions();
	}
}