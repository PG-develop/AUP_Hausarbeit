#include "../include/LeaderboardState.hpp"
#include "../include/TXTUserPersistenceListService.hpp"

namespace AUP_HA
{
	LeaderboardState::LeaderboardState(StateManager& stateManager) : State(stateManager)
	{
		mLeaderboard = std::make_unique<Leaderboard>();
	}

	LeaderboardState::~LeaderboardState()
	{
	}

	void LeaderboardState::render()
	{
		std::cout << "LeaderboardState" << std::endl;
	}

	void LeaderboardState::processEvents()
	{
	}

	void LeaderboardState::update()
	{
	}
}