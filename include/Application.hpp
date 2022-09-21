#pragma once

#include <memory>

#include "StatesIdentifier.hpp"

namespace AUP_HA 
{
	// Vorw�rtsdeklaration
	class StateManager;

	/**
	* @class Application
	* @brief Programm-Shell
	* 
	* Programm-Shell - Steuert den grunds�tzlichen Programmablauf
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