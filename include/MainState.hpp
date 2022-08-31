#pragma once

#include <iostream>

#include "State.hpp"

namespace AUP_HA 
{
	class MainState : public State
	{
	public:
		MainState(StateManager& stateManager);
		~MainState();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		void onGame();
		void onSetup();
		void onLeaderboard();
		void onExit();

	private:
		std::string	mUserinput;
	};
}