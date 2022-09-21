#include <iostream>
#include <cassert>

#include "../include/NumberGameStateManager.hpp"
#include "../include/NumberGameStateName.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Laden der Übergangsbedingungen: EMPTY
	* 
	* @param [stateManager_p] NumberGameStateManager 
	*/
	NumberGameStateName::NumberGameStateName(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
	{
		mTransitionList.push_back(manager_p.GetTransition(GameStates::EMPTY));
	}

	/**
	* @Destruktor
	*
	* Keine Funktion
	*/
	NumberGameStateName::~NumberGameStateName()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Der Benutzer wird aufgefordert seinen Namen einzutragen. 
	* Dieser Name wird später für die Eintragung in die Bestenliste
	* herangezogen.
	*/
	void NumberGameStateName::Render()
	{
		std::cout << "Bitte geben Sie Ihren Namen ein: ";
	}

	/**
	* @brief Benutzereingabe
	*/
	void NumberGameStateName::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	/**
	* @brief Ausführung der Logik
	*
	* Es werden nur die Übergangsbedingungen geprüft
	*/
	void NumberGameStateName::Update()
	{
		checkTransitions();
	}
}