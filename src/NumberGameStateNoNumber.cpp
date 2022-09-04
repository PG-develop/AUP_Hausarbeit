#include "../include/NumberGameStateManager.hpp"
#include "../include/NumberGameStateNoNumber.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateNoNumber::NumberGameStateNoNumber(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NH));
	}
	NumberGameStateNoNumber::~NumberGameStateNoNumber()
	{
	}
	void NumberGameStateNoNumber::render()
	{
		std::cout << "Ihre Eingabe war keine gültige Zahl: " << mGame->getLastInput() << std::endl;
		std::cout << "Bitte geben Sie eine Zahl ein: ";
	}
	void NumberGameStateNoNumber::processEvents()
	{
		std::cin >> mInputBuffer;
	}
	void NumberGameStateNoNumber::update()
	{
		checkTransitions();
	}
}