#pragma once

#include <iostream>

#include "State.hpp"

namespace AUP_HA 
{
	/**
	* @class State für die Introanzeige
	*/
	class IntroState : public State
	{
	public:
		IntroState(StateManager& stateManager_p);
		~IntroState();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}