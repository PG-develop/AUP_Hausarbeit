#pragma once

#include <iostream>

#include "State.hpp"

namespace AUP_HA 
{
	class IntroState : public State
	{
	public:
		IntroState(StateManager& stateManager);
		~IntroState();

		virtual void render();
		virtual void processEvents();
		virtual void update();
	};
}