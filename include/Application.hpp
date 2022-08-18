#pragma once
/*
* @Title Application
* 
* @Description Anwendungseinstiegspunkt. Beherbergt den Statemanager und steuert den Programmfluss.
*/

#include <memory>

#include "StateManager.hpp"
#include "StatesIdentifier.hpp"

namespace AUP_HA 
{
	class Application 
	{
	public:
		explicit Application();
		~Application();
		void run();

	private:
		void render();
		void processEvents();
		void update();

		void RegisterStates();

	private:
		std::unique_ptr<StateManager>	mStateManager;
	};
}