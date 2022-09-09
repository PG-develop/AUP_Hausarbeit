#include <chrono>

#include "../include/NumberGameStateCheatWin.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{
	NumberGameStateCheatWin::NumberGameStateCheatWin(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::W));
		mUserRepository = &manager.getUserRepository();
	}
	NumberGameStateCheatWin::~NumberGameStateCheatWin()
	{
	}
	void NumberGameStateCheatWin::render()
	{
		std::cout << "Gewonnen!" << std::endl;
		std::cout << "Wie viele Versuche sollen eingetragen werden? ";

	}
	void NumberGameStateCheatWin::processEvents()
	{
		std::cin >> mInputBuffer;
		
	}
	void NumberGameStateCheatWin::update()
	{
		auto parsedString = Utilities::ParseStringToInt(mInputBuffer);

		if (parsedString)
		{
			User user = mGame->getUser();
			user.Tries = *parsedString;
			user.Date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			mGame->setNewTime(user.Date);
			mUserRepository->SaveOrUpdate(user);
		}
		checkTransitions();
	}
}