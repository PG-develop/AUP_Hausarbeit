#include "../include/NumberGameStateManager.hpp"
#include "../include/NumberGameStateNoNumber.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der �bergangsbedingungen: NN, C, OB, NH
	* 
	* @param [stateManager_p] NumberGameStateManager 
	*/
	NumberGameStateNoNumber::NumberGameStateNoNumber(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
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
	NumberGameStateNoNumber::~NumberGameStateNoNumber()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Dem Benutzer wird mitgeteilt, keine g�ltige Nummer angegeben zu haben.
	* Er wird aufgefordert, eine g�ltige Nummer anzugeben.
	*/
	void NumberGameStateNoNumber::Render()
	{
		std::cout << "Ihre Eingabe war keine gueltige Zahl: " << mGame->GetLastInput() << std::endl;
		std::cout << "Finde die Zahl! Geben Sie eine Zahl zwischen " << mGame->GetMinBorder() << " und " << mGame->GetMaxBorder() << " ein: ";
	}

	/**
	* @brief Benutzereingabe
	*/
	void NumberGameStateNoNumber::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	/**
	* @brief Ausf�hrung der Logik
	*
	* Es werden nur die �bergangsbedingungen gepr�ft
	*/
	void NumberGameStateNoNumber::Update()
	{
		checkTransitions();
	}
}