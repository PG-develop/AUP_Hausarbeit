#include "../include/State.hpp"
#include "../include/StateManager.hpp"

namespace AUP_HA 
{
	/**
	* @brief Konstruktor
	* 
	* Übergabe des StateManagers
	*/
	State::State(StateManager& stateManager_p) : mStateManager(&stateManager_p)
	{
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	State::~State()
	{
	}

	/**
	* @brief Anfrage nach einem Zustandswechsel.
	* 
	* State fragt nach einem Zustandswechsel zu den angegebenen Zustandsidentifiziierer.
	* Zustandsidentifiziierer muss vorher registriert worden sein.
	* 
	* @param[stateID] States::ID Zustandsidentifiziierer
	*/
	void State::requestChange(States::ID stateID_p)
	{
		mStateManager->changeState(stateID_p);
	}
}