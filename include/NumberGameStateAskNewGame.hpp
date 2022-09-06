#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateAskNewGame : public NumberGameState
	{
	public:
		NumberGameStateAskNewGame(NumberGameStateManager& manager);
		virtual ~NumberGameStateAskNewGame();

		virtual void render();
		virtual void processEvents();
		virtual void update();
	};
}