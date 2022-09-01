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
		MainState(StateManager& stateManager);
		~MainState();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		void registerMenu();

		void onGame();
		void onSetup();
		void onLeaderboard();
		void onExit();

	private:
		std::string					mUserinput;
		MenuManager<MainMenu::ID>	mMenu;
	};
}