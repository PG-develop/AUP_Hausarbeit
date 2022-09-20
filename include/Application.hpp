#pragma once

#include <memory>

#include "StatesIdentifier.hpp"

namespace AUP_HA 
{
	// Vorwärtsdeklaration
	class StateManager;

	/**
	* @class Application
	* 
	* Programmeinstieg, steuert den Grundlegenden Programmfluss
	*/
	class Application 
	{
	public:
		explicit Application();
		~Application();
		void Run();

	private:
		void render();
		void processEvents();
		void update();

		void registerStates();

	private:
		std::unique_ptr<StateManager>	mStateManager;	/**< StateManager */
	};
}