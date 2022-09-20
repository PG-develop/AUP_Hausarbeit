#include "../include/NumberGameStateNormal.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateNormal::NumberGameStateNormal(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NH));
	}

	NumberGameStateNormal::~NumberGameStateNormal()
	{
	}

	void NumberGameStateNormal::Render()
	{
		auto lastInput = Utilities::ParseStringToInt(mGame->GetLastInput());

		// Im State_1 (Name eingeben) wurde keine Zahl eingegeben.
		// Wenn als letzter Input der Name eingegeben wurde, wird hier die Ausgabe für die letzte Ausgabe herausgefiltert.
		if (lastInput)
		{
			std::cout << "Ihre letzte Eingabe: " << *lastInput << std::endl;
		}
		std::cout << mGame->GetTries() + 1 << ". Versuche - " << mGame->GetUser().Name << std::endl;
		std::cout << "Finde die Zahl! Geben Sie eine Zahl zwischen " << mGame->GetMinBorder() << " und " << mGame->GetMaxBorder() << " ein: ";
	}

	void NumberGameStateNormal::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	void NumberGameStateNormal::Update()
	{
		checkTransitions();
	}

}