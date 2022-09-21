#include "../include/NumberGameStateOutBorders.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der �bergangsbedingungen: NN, C, OB, NH
	*/
	NumberGameStateOutBorders::NumberGameStateOutBorders(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::NH));
	}

	/**
	* @Destruktor
	*
	* Keine Funktion
	*/
	NumberGameStateOutBorders::~NumberGameStateOutBorders()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Dem Benutzer wird mitgeteilt, dass seine Eingabe au�erhalb der Grenzen lag.
	* Er wird aufgefordert, eine g�ltige Nummer anzugeben.
	*/
	void NumberGameStateOutBorders::Render()
	{
		std::cout << "Ihre Eingabe war ausserhalb der gueltigen Grenzen [" << mGame->GetMinBorder() << "|" << mGame->GetMaxBorder() << "] : " << mGame->GetLastInput() << std::endl;
		std::cout << "Bitte geben Sie eine Zahl ein: ";
	}

	/**
	* @brief Benutzereingabe
	*/
	void NumberGameStateOutBorders::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	/**
	* @brief Ausf�hrung der Logik
	*
	* Es werden nur die �bergangsbedingungen gepr�ft
	*/
	void NumberGameStateOutBorders::Update()
	{
		checkTransitions();
	}

}