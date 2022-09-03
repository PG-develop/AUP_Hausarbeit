#include <iostream>
#include <cassert>

#include "../include/NumberGameStateManager.hpp"
#include "../include/NumberGameStateName.hpp"

namespace AUP_HA
{
	NumberGameStateName::NumberGameStateName(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::EMPTY));
	}
	NumberGameStateName::~NumberGameStateName()
	{
	}
	void NumberGameStateName::render()
	{
		std::cout << "Bitte geben Sie Ihren Namen ein: ";
	}
	void NumberGameStateName::processEvents()
	{
		std::cin >> mInputBuffer;
	}
	void NumberGameStateName::update()
	{
		checkTransitions();
	}
}