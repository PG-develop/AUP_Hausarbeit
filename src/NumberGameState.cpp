#include "../include/NumberGameState.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Referenz�bergabe von der Spielinstanz
	* 
	* @param [manager_p] NumberGameStateManager 
	*/
	NumberGameState::NumberGameState(NumberGameStateManager& manager_p) : mInputBuffer(), mManager{&manager_p}
	{
		mGame = &(mManager->GetGame());
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	NumberGameState::~NumberGameState()
	{
	}

	/**
	* @brief Statewechselanfrage
	*/
	void NumberGameState::requestChange(GameStates::ID stateID_p)
	{
		// Weil die Instanz nach einem Statewechsel nicht mehr existiert,
		// wird die letzte Benutzereingabe im Manager abgespeichert.
		mGame->SetNewInput(mInputBuffer);

		// Statewechsel
		mManager->ChangeState(stateID_p);
	}

	/**
	* @brief �berpr�fung der �bergangsbedingungen
	* 
	* Geht alle registrierten �bergangsbedinungen durch. Sobald eine Bedingung
	* erf�llt ist, wird der Durchlauf unterbrochen und ein Statewechsel 
	* auf den in der �bergangsbedingung mitgegebenen Identifikator durchgef�hrt.
	*/
	void NumberGameState::checkTransitions()
	{
		for (const auto& item : mTransitionList)
		{
			auto result = item(mInputBuffer);

			if (result)
			{
				requestChange(*result);
				break;
			}
		}
	}
}