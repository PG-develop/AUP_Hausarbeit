#include "../include/NumberGameStateShowSearchedNumber.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateShowSearchedNumber::NumberGameStateShowSearchedNumber(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NH));

		auto lastInput = Utilities::ParseStringToInt(mGame->getLastInput());
	}
	NumberGameStateShowSearchedNumber::~NumberGameStateShowSearchedNumber()
	{
	}
	void NumberGameStateShowSearchedNumber::render()
	{
		std::cout << "Die gesuchte Zahl ist " << mGame->getSearchedNumber() << std::endl << std::endl;

		std::cout << mGame->getTries() + 1 << ". Versuche - " << mGame->getUser().Name << std::endl;
		std::cout << "Finde die Zahl! Geben Sie eine Zahl zwischen " << mGame->getMinBorder() << " und " << mGame->getMaxBorder() << " ein: ";

	}
	void NumberGameStateShowSearchedNumber::processEvents()
	{
		std::cin >> mInputBuffer;
	}
	void NumberGameStateShowSearchedNumber::update()
	{
		checkTransitions();
	}
}