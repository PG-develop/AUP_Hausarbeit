#pragma once

#include "State.hpp"

namespace AUP_HA
{
	class LeaderboardState : public State
	{
	public:
		LeaderboardState(StateManager& stateManager);
		~LeaderboardState();

		virtual void render();
		virtual void processEvents();
		virtual void update();
	};
}