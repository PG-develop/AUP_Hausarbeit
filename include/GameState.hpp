#pragma once

#include "State.hpp"

namespace AUP_HA
{
	class GameState : public State
	{
	public:
		GameState(StateManager& stateManager);
		~GameState();

		virtual void render();
		virtual void processEvents();
		virtual void update();
	};
}