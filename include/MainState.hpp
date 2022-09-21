#pragma once

#include <iostream>

#include "../include/MenuManager.hpp"
#include "../include/MenuIdentifier.hpp"
#include "../include/State.hpp"

namespace AUP_HA 
{
	/**
	* @class MainState
	* @brief Hauptabzweig f�r die verschiedene Programmfl�sse
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
		std::pair<int, int>			mLimits;	/**< Grenzen f�r die Men�eingabe */
		MenuManager<MainMenu::ID>	mMenu;		/**< Men� */

	};
}