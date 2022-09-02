#include <iostream>
#include <cassert>

#include "../include/NumberGameStateName.hpp"

namespace AUP_HA
{
	NumberGameStateName::NumberGameStateName(NumberGameStateManager& manager) : NumberGameState(manager)
	{
	}
	NumberGameStateName::~NumberGameStateName()
	{
	}
	void NumberGameStateName::render()
	{
		std::cout << "Bitte geben Sie Ihren Namen ein: " << std::endl;
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