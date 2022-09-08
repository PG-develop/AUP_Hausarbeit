#pragma once

#include <iostream>

#include "../include/State.hpp"
#include "../include/MenuManager.hpp"
#include "../include/MenuIdentifier.hpp"

namespace AUP_HA
{
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

	private:
		std::string					mUserinput;	// Benutzereingabe
		std::pair<int, int>			mLimits;	// Grenzen für die Menüeingabe
		MenuManager<MainMenu::ID>	mMenu;		// Menü

	};
}