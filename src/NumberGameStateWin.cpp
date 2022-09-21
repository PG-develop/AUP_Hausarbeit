#include <conio.h>

#include "../include/NumberGameStateWin.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der �bergangsbedingungen: L
	* 
	* @param [stateManager_p] NumberGameStateManager 
	*/
	NumberGameStateWin::NumberGameStateWin(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
	{
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::L));

		// Update der Bestenliste
		manager_p.GetUserRepository().SaveOrUpdate(manager_p.GetGame().GetUser());
	}

	/**
	* @Destruktor
	*
	* Keine Funktion
	*/
	NumberGameStateWin::~NumberGameStateWin()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Dem Benutzer wird mitgeteilt, dass er die gesuchte Zahl gefunden hat.
	* Er wird aufgefordert eine belibiege Taste zu dr�cken.
	*/
	void NumberGameStateWin::Render()
	{
		std::cout << "Gewonnen! " << mGame->GetSearchedNumber() << std::endl;
		std::cout << "Weiter mit einer beliebigen Taste...";
	}


	/**
	* @brief Benutzereingabe
	* 
	* Keine Funktion
	*/
	void NumberGameStateWin::ProcessEvents()
	{
	}

	/**
	* @brief Ausf�hrung der Logik
	*
	* Es werden nur die �bergangsbedingungen gepr�ft
	*/
	void NumberGameStateWin::Update()
	{
		checkTransitions();
	}
}