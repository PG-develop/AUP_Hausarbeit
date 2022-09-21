#pragma once

#include <iostream>

#include "../include/MenuManager.hpp"
#include "../include/MenuIdentifier.hpp"
#include "../include/State.hpp"

namespace AUP_HA 
{
	/**
	* @class MainState
	* @brief Hauptabzweig für die verschiedene Programmflüsse
	*/
	class MainState : public State
	{
	public:
		MainState(StateManager& stateManager_p);
		~MainState();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		void registerMenu();

		void onGame();
		void onSetup();
		void onLeaderboard();
		void onExit();

	private:
		std::string					mUserinput;	/**< Benutzereingabe */ 
		std::pair<int, int>			mLimits;	/**< Grenzen für die Menüeingabe */
		MenuManager<MainMenu::ID>	mMenu;		/**< Menü */

	};
}