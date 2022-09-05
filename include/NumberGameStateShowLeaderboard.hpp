#pragma once

#include "../include/NumberGameState.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{
	class NumberGameStateShowLeaderboard : public NumberGameState
	{
	public:
		NumberGameStateShowLeaderboard(NumberGameStateManager& manager);
		virtual ~NumberGameStateShowLeaderboard();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		UserRepository* mUserRepository;
	};
}