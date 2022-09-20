#include "../include/NumberGameStateManager.hpp"
#include "../include/NumberGameStateNoNumber.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateNoNumber::NumberGameStateNoNumber(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NH));
	}
	NumberGameStateNoNumber::~NumberGameStateNoNumber()
	{
	}
	void NumberGameStateNoNumber::Render()
	{
		std::cout << "Ihre Eingabe war keine gueltige Zahl: " << mGame->GetLastInput() << std::endl;
		std::cout << "Bitte geben Sie eine Zahl ein: ";
	}
	void NumberGameStateNoNumber::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}
	void NumberGameStateNoNumber::Update()
	{
		checkTransitions();
	}
}