#pragma once

#include <iostream>

#include "../include/State.hpp"
#include "../include/MenuManager.hpp"
#include "../include/MenuIdentifier.hpp"

namespace AUP_HA
{
	// Vorw�rtsdeklaration
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
		std::pair<int, int>				mLimits;			// Grenzen f�r die Men�eingabe
		MenuManager<SetupMenu::ID>		mMenu;				// Men�
		std::unique_ptr<UserRepository> mUserRepository;	// UserRepository

	};
}