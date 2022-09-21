#include "../include/NumberGameState.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Referenzübergabe von der Spielinstanz
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
	* @brief Überprüfung der Übergangsbedingungen
	* 
	* Geht alle registrierten Übergangsbedinungen durch. Sobald eine Bedingung
	* erfüllt ist, wird der Durchlauf unterbrochen und ein Statewechsel 
	* auf den in der Übergangsbedingung mitgegebenen Identifikator durchgeführt.
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