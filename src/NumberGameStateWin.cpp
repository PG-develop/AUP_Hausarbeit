#include <conio.h>

#include "../include/NumberGameStateWin.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateWin::NumberGameStateWin(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::L));

		// Update der Bestenliste
		manager.GetUserRepository().SaveOrUpdate(manager.GetGame().GetUser());
	}

	NumberGameStateWin::~NumberGameStateWin()
	{
	}

	void NumberGameStateWin::Render()
	{
		std::cout << "Gewonnen! " << mGame->GetSearchedNumber() << std::endl;
		std::cout << "Weiter mit einer beliebigen Taste...";
	}

	void NumberGameStateWin::ProcessEvents()
	{
	}

	void NumberGameStateWin::Update()
	{
		checkTransitions();
	}
}