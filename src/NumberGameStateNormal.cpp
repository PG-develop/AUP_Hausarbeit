#include "../include/NumberGameStateNormal.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

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
		auto lastInput = Utilities::ParseStringToInt(mGame->getLastInput());

		// Im State_1 (Name eingeben) wurde keine Zahl eingegeben.
		// Wenn als letzter Input der Name eingegeben wurde, wird hier die Ausgabe für die letzte Ausgabe herausgefiltert.
		if (lastInput)
		{
			std::cout << "Ihre letzte Eingabe: " << *lastInput << std::endl;
		}
		std::cout << mGame->getTries() << ". Versuche - " << mGame->getUser().Name << std::endl;
		std::cout << "Finde die Zahl! Geben Sie eine Zahl zwischen " << mGame->getMinBorder() << " und " << mGame->getMaxBorder() << " ein: ";
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