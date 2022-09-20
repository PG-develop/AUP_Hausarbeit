#include "../include/NumberGameStateShowSearchedNumber.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateShowSearchedNumber::NumberGameStateShowSearchedNumber(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NH));

		auto lastInput = Utilities::ParseStringToInt(mGame->GetLastInput());
	}
	NumberGameStateShowSearchedNumber::~NumberGameStateShowSearchedNumber()
	{
	}
	void NumberGameStateShowSearchedNumber::Render()
	{
		std::cout << "Die gesuchte Zahl ist " << mGame->GetSearchedNumber() << std::endl << std::endl;

		std::cout << mGame->GetTries() + 1 << ". Versuche - " << mGame->GetUser().Name << std::endl;
		std::cout << "Finde die Zahl! Geben Sie eine Zahl zwischen " << mGame->GetMinBorder() << " und " << mGame->GetMaxBorder() << " ein: ";

	}
	void NumberGameStateShowSearchedNumber::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}
	void NumberGameStateShowSearchedNumber::Update()
	{
		checkTransitions();
	}
}