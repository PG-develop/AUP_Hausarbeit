#pragma once

#include <vector>

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateWin : public NumberGameState
	{
	public:
		NumberGameStateWin(NumberGameStateManager& manager);
		virtual ~NumberGameStateWin();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		std::vector<User> mCurrentLeaderboard;
	};
}