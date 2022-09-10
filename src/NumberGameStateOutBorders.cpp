#include "../include/NumberGameStateOutBorders.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateOutBorders::NumberGameStateOutBorders(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NH));
	}

	NumberGameStateOutBorders::~NumberGameStateOutBorders()
	{
	}

	void NumberGameStateOutBorders::render()
	{
		std::cout << "Ihre Eingabe war ausserhalb der gueltigen Grenzen [" << mGame->getMinBorder() << "|" << mGame->getMaxBorder() << "] : " << mGame->getLastInput() << std::endl;
		std::cout << "Bitte geben Sie eine Zahl ein: ";
	}

	void NumberGameStateOutBorders::processEvents()
	{
		std::cin >> mInputBuffer;
	}

	void NumberGameStateOutBorders::update()
	{
		checkTransitions();
	}

}