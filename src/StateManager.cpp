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
	void StateManager::Render()
	{
		// Wenn ein aktiver State vorhanden ist, dann rufe die Darstellungsfunktion des aktiven States auf.
		if (mActiveState)
		{

			// Im Debug-Build soll die Ausgabe nicht gesäubert werden.
			// Im Release-Build erfolgt nach jedem Tick eine Säuberung der Ausgabe.
#ifndef _DEBUG
			system("cls");
#endif
			mActiveState->Render();
		}
	}

	/**
	* @brief Behandlung der Eingabestreams / Events.
	*/
	void StateManager::ProcessEvents()
	{
		// Wenn ein aktiver State vorhanden ist, nehme die Benutzereingabe entgegen.
		if (mActiveState)
		{
			mActiveState->ProcessEvents();
		}
	}

	/**
	* @brief Behandlung der Programmlogik.
	*/
	void StateManager::Update()
	{
		// Wenn ein aktiver State vorhanden ist, führe die Programmlogik aus.
		if (mActiveState)
		{
			mActiveState->Update();
		}
	}

	/**
	* @brief Wechsel zu einem anderen State
	* 
	* Wechselt auf den neuen State, der mit dem angegeben Zustandsidentifiziierer registriert wurde.
	* Der gewünschte State muss vorher registriert worden sein. Ansonsten kommt es zu einem Programmfehler.
	* 
	* Der aktive State wird gelöscht und der geforderte State wird durch die Zustandsfabrik instanziiert.
	* Wenn das Programm beendet werden soll muss der Zustandsidentifiziierer States::NONE ausgewählt werden.
	* 
	* @param [stateID_p] States::ID Zustandsidentifiziierer
	*/
	void StateManager::changeState(States::ID stateID_p)
	{
		// Wenn States::NONE gefordert ist, lösche nur den aktiven State
		if (stateID_p == States::NONE)
		{
			mActiveState.reset();
		}

		// Ansonsten suche nach den Registrierten Identifiziierer
		else
		{
			auto found = mStateFactories.find(stateID_p);

			// Wenn kein Identifiziierer gefunden wurde, gebe Programmfehler aus (nur DEBUG)
			assert(found != mStateFactories.end());

			// Wenn es einen aktiven State gibt, lösche diesen.
			if (mActiveState) 
			{
				mActiveState.reset();
			}

			// Erstelle die Instanz durch die Zustandsfabrik.
			mActiveState = found->second();
		}
	}

	/**
	* @brief Prüfung, ob ein State in diesem Tick aktiv ist.
	* 
	* @return TRUE, wenn ein State aktiv ist.\n
	*		  FALSE wenn kein State aktiv ist.
	*/
	bool StateManager::hasActiveState() const
	{
		// cast von unique_ptr zu bool
		return static_cast<bool>(mActiveState);
	}
}
