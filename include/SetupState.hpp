#pragma once

#include <iostream>

#include "../include/State.hpp"

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
	};
}