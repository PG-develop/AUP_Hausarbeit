#include "../include/NumberGameStateShowSearchedNumber.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der �bergangsbedingungen: NN, C, OB, NH
	*/
	NumberGameStateShowSearchedNumber::NumberGameStateShowSearchedNumber(NumberGameStateManager& manager) : NumberGameState(manager)
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
	NumberGameStateShowSearchedNumber::~NumberGameStateShowSearchedNumber()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Dem Benutzer wird die gesuchte Nummer angezeigt.
	* Der Spielfluss geht normal weiter und er wird aufgefordert eine Nummer anzugeben.
	*/
	void NumberGameStateShowSearchedNumber::Render()
	{
		std::cout << "Die gesuchte Zahl ist " << mGame->GetSearchedNumber() << std::endl << std::endl;

		std::cout << mGame->GetTries() + 1 << ". Versuche - " << mGame->GetUser().Name << std::endl;
		std::cout << "Finde die Zahl! Geben Sie eine Zahl zwischen " << mGame->GetMinBorder() << " und " << mGame->GetMaxBorder() << " ein: ";

	}

	/**
	* @brief Benutzereingabe
	*/
	void NumberGameStateShowSearchedNumber::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	/**
	* @brief Ausf�hrung der Logik
	*
	* Es werden nur die �bergangsbedingungen gepr�ft
	*/
	void NumberGameStateShowSearchedNumber::Update()
	{
		checkTransitions();
	}
}