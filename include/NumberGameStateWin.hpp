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

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		std::vector<User> mCurrentLeaderboard;
	};
}