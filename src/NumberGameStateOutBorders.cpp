#include "../include/NumberGameStateOutBorders.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der Übergangsbedingungen: NN, C, OB, NH
	* 
	* @param [manager_p] NumberGameStateManager 
	*/
	NumberGameStateOutBorders::NumberGameStateOutBorders(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
	{
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::NN));
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::C));
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::OB));
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::NH));
	}

	/**
	* @brief Destruktor
	*
	* Keine Funktion
	*/
	NumberGameStateOutBorders::~NumberGameStateOutBorders()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Dem Benutzer wird mitgeteilt, dass seine Eingabe außerhalb der Grenzen lag.
	* Er wird aufgefordert, eine gültige Nummer anzugeben.
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
	* @brief Ausführung der Logik
	*
	* Es werden nur die Übergangsbedingungen geprüft
	*/
	void NumberGameStateOutBorders::Update()
	{
		checkTransitions();
	}

}