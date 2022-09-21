#include <conio.h>

#include "../include/NumberGameStateWin.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der Übergangsbedingungen: L
	*/
	NumberGameStateWin::NumberGameStateWin(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.GetTransition(GameStates::TRANSITION::L));

		// Update der Bestenliste
		manager.GetUserRepository().SaveOrUpdate(manager.GetGame().GetUser());
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
	* Er wird aufgefordert eine belibiege Taste zu drücken.
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
	* @brief Ausführung der Logik
	*
	* Es werden nur die Übergangsbedingungen geprüft
	*/
	void NumberGameStateWin::Update()
	{
		checkTransitions();
	}
}