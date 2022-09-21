#include "../include/NumberGameStateNormal.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der Übergangsbedingungen: NN, C, OB, NH
	*/
	NumberGameStateNormal::NumberGameStateNormal(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
	{
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::NH));
	}

	/**
	* @Destruktor
	*
	* Keine Funktion
	*/
	NumberGameStateNormal::~NumberGameStateNormal()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Die Benutzereingabe war korrekt.
	* Er wird aufgefordert, eine gültige Nummer anzugeben.
	*/
	void NumberGameStateNormal::Render()
	{
		auto lastInput = Utilities::ParseStringToInt(mGame->GetLastInput());

		// Im STATE_1 (Name eingeben) wurde keine Zahl eingegeben.
		// Wenn als letzter Input der Name eingegeben wurde, wird hier die Ausgabe für die letzte Ausgabe herausgefiltert.
		if (lastInput)
		{
			std::cout << "Ihre letzte Eingabe: " << *lastInput << std::endl;
		}
		std::cout << mGame->GetTries() + 1 << ". Versuche - " << mGame->GetUser().Name << std::endl;
		std::cout << "Finde die Zahl! Geben Sie eine Zahl zwischen " << mGame->GetMinBorder() << " und " << mGame->GetMaxBorder() << " ein: ";
	}

	/**
	* @brief Benutzereingabe
	*/
	void NumberGameStateNormal::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	/**
	* @brief Ausführung der Logik
	*
	* Es werden nur die Übergangsbedingungen geprüft
	*/
	void NumberGameStateNormal::Update()
	{
		checkTransitions();
	}

}