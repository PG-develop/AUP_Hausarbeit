#pragma once

#include <iostream>

#include "../include/State.hpp"
#include "../include/MenuManager.hpp"
#include "../include/MenuIdentifier.hpp"

namespace AUP_HA
{
	// Vorw�rtsdeklaration
	class UserRepository;

	/**
	* @class SetupState
	*
	* 1. Ebene der Einstellungen\n
	* Weiter zur Ebenene der Spieleinstellungen oder Reset der Bestenliste
	*/
	class SetupState : public State
	{
	public:
		SetupState(StateManager& stateManager_p);
		~SetupState();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		void registerMenu();

		void onGameSetup();
		void onClear();
		void onExit();

	private:
		std::string								mUserinput;			// Benutzereingabe
		std::pair<std::int32_t, std::int32_t>	mLimits;			// Grenzen f�r die Men�eingabe
		MenuManager<SetupMenu::ID>				mMenu;				// Men�
		std::unique_ptr<UserRepository>			mUserRepository;	// UserRepository

	};
}