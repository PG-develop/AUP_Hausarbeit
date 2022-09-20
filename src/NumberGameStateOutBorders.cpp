#include "../include/NumberGameStateOutBorders.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateOutBorders::NumberGameStateOutBorders(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NH));
	}

	NumberGameStateOutBorders::~NumberGameStateOutBorders()
	{
	}

	void NumberGameStateOutBorders::Render()
	{
		std::cout << "Ihre Eingabe war ausserhalb der gueltigen Grenzen [" << mGame->GetMinBorder() << "|" << mGame->GetMaxBorder() << "] : " << mGame->GetLastInput() << std::endl;
		std::cout << "Bitte geben Sie eine Zahl ein: ";
	}

	void NumberGameStateOutBorders::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	void NumberGameStateOutBorders::Update()
	{
		checkTransitions();
	}

}