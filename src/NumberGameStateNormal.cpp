#include "../include/NumberGameStateNormal.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	NumberGameStateNormal::NumberGameStateNormal(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NH));
	}

	NumberGameStateNormal::~NumberGameStateNormal()
	{
	}

	void NumberGameStateNormal::render()
	{
		std::cout << "Finde die Zahl! Geben Sie eine Zahl ein: ";
	}

	void NumberGameStateNormal::processEvents()
	{
		std::cin >> mInputBuffer;
	}

	void NumberGameStateNormal::update()
	{
		checkTransitions();
	}

}