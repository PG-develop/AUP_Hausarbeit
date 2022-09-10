#include "../include/StateManager.hpp"

namespace AUP_HA 
{
	/**
	* @brief Konstruktor
	* 
	* Initialisierung der Zustandsfabrik
	*/
	StateManager::StateManager() : mStateFactories()
	{
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	StateManager::~StateManager()
	{
	}

	/**
	* @brief Darstellung des States
	*/
	void StateManager::render()
	{
		// Wenn ein aktiver State vorhanden ist, dann rufe die Darstellungsfunktion des aktiven States auf.
		if (mActiveState)
		{

			// Im Debug-Build soll die Ausgabe nicht gesäubert werden.
			// Im Release-Bukld erfolgt nach jedem Tick eine Säuberung der Ausgabe.
#ifndef _DEBUG
			system("cls");
#endif
			mActiveState->render();
		}
	}

	/**
	* @brief Behandlung der Eingabestreams / Events.
	*/
	void StateManager::processEvents()
	{
		// Wenn ein aktiver State vorhanden ist, nehme die Benutzereingabe entgegen.
		if (mActiveState)
		{
			mActiveState->processEvents();
		}
	}

	/**
	* @brief Behandlung der Programmlogik.
	*/
	void StateManager::update()
	{
		// Wenn ein aktiver State vorhanden ist, führe die Programmlogik aus.
		if (mActiveState)
		{
			mActiveState->update();
		}
	}

	/**
	* @brief Wechsel zu einem anderen State
	* 
	* Wechselt auf den neuen State, der mit dem angegeben Zustandsidentifiziierer registriert wurde.
	* Der gewünschte State muss vorher registriert worden sein. Ansonsten kommt es zu einem Programmfehler.
	* 
	* Wenn der gewünschte State bereits aktiv ist, wird dieser nicht erneut instanziiert.
	* 
	* @param [stateID] States::ID Zustandsidentifiziierer
	*/
	void StateManager::changeState(States::ID stateID)
	{
		if (stateID == States::NONE)
		{
			mActiveState.reset();
		}
		else
		{
			auto found = mStateFactories.find(stateID);
			assert(found != mStateFactories.end());
			if (mActiveState) 
			{
				mActiveState.reset();
			}
			mActiveState = found->second();
		}
	}

	/*
	*
	*/
	bool StateManager::hasActiveState() const
	{
		return static_cast<bool>(mActiveState);
	}
}
