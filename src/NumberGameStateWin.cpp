#include <conio.h>

#include "../include/NumberGameStateWin.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateWin::NumberGameStateWin(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::L));

		// Update der Bestenliste
		manager.getUserRepository().SaveOrUpdate(manager.getGame().getUser());
		mCurrentLeaderboard = manager.getUserRepository().GetUserSortedByRang();
	}

	NumberGameStateWin::~NumberGameStateWin()
	{
	}

	void NumberGameStateWin::render()
	{
		std::cout << "Gewonnen! " << mGame->getSearchedNumber() << std::endl;
		std::cout << "Weiter mit einer beliebigen Taste...";
	}

	void NumberGameStateWin::processEvents()
	{
		while (!_kbhit());
		_getch();
	}

	void NumberGameStateWin::update()
	{
		checkTransitions();
	}
}