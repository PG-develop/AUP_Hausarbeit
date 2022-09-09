#include <iostream>
#include <iomanip>
#include <conio.h>

#include "../include/LeaderboardState.hpp"
#include "../include/TXTUserPersistenceListService.hpp"

namespace AUP_HA
{
	LeaderboardState::LeaderboardState(StateManager& stateManager) : State(stateManager)
	{
		mUserRepository = std::make_unique<UserRepository>();
	}

	LeaderboardState::~LeaderboardState()
	{
	}

	void LeaderboardState::render()
	{
		// Kopf
		std::cout << "+----------------------------------------------------+" << std::endl;
		std::cout << "|                     Bestenliste                    |" << std::endl;
		std::cout << "+----+-------------------+------------------+--------+" << std::endl;
		std::cout << "|    |       Datum       |       Name       |Versuche|" << std::endl;
		std::cout << "+----+-------------------+------------------+--------+" << std::endl;

		int i = 0;

		for (const User& user : mUserRepository->GetUserSortedByRang()) {
			// Zeit parsen
			std::tm* date = new tm();
			char buffer[128];

			localtime_s(date, &user.Date);
			strftime(buffer, sizeof(buffer), "%d.%m.%Y  %R", date);

			std::cout << "|" << std::setw(3) << ++i << " | " << buffer << " | " << std::setw(16) << user.Name << " | " << std::setw(6) << user.Tries << " |" << std::endl;
		}

		std::cout << "+----+-------------------+------------------+--------+" << std::endl << std::endl;
		std::cout << "Zurueck mit einer Taste";
	}

	void LeaderboardState::processEvents()
	{
		while (!_kbhit());
		_getch();
	}

	void LeaderboardState::update()
	{
		requestChange(States::MAIN);
	}
}