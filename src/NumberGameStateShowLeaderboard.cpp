#include <conio.h>
#include <iostream>
#include <iomanip>

#include "../include/NumberGameStateShowLeaderboard.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	NumberGameStateShowLeaderboard::NumberGameStateShowLeaderboard(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::I));
		mUserRepository = &manager.GetUserRepository();
	}

	NumberGameStateShowLeaderboard::~NumberGameStateShowLeaderboard()
	{
	}

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

	void NumberGameStateShowLeaderboard::ProcessEvents()
	{
	}

	void NumberGameStateShowLeaderboard::Update()
	{
		checkTransitions();
	}
}