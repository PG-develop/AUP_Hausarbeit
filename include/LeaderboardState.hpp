#pragma once

#include <iostream>
#include <memory>

#include "../include/State.hpp"
#include "../include/Leaderboard.hpp"

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

	private:
		std::unique_ptr<Leaderboard> mLeaderboard;
		std::unique_ptr<UserRepository> mUserRepository;
	};
}