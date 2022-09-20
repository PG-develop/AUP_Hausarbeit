#include <iostream>
#include <cassert>

#include "../include/NumberGameStateManager.hpp"
#include "../include/NumberGameStateName.hpp"

namespace AUP_HA
{
	NumberGameStateName::NumberGameStateName(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::EMPTY));
	}
	NumberGameStateName::~NumberGameStateName()
	{
	}
	void NumberGameStateName::Render()
	{
		std::cout << "Bitte geben Sie Ihren Namen ein: ";
	}
	void NumberGameStateName::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}
	void NumberGameStateName::Update()
	{
		checkTransitions();
	}
}