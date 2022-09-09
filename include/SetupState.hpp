#pragma once

#include <iostream>

#include "../include/State.hpp"
#include "../include/MenuManager.hpp"
#include "../include/MenuIdentifier.hpp"

namespace AUP_HA
{
	// Vorwärtsdeklaration
	class UserRepository;

	class SetupState : public State
	{
	public:
		SetupState(StateManager& stateManager);
		~SetupState();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		void registerMenu();

		void onGameSetup();
		void onClear();
		void onExit();

	private:
		std::string						mUserinput;			// Benutzereingabe
		std::pair<int, int>				mLimits;			// Grenzen für die Menüeingabe
		MenuManager<SetupMenu::ID>		mMenu;				// Menü
		std::unique_ptr<UserRepository> mUserRepository;	// UserRepository

	};
}