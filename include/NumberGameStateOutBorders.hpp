#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateOutBorders : public NumberGameState
	{
	public:
		NumberGameStateOutBorders(NumberGameStateManager& manager);
		virtual ~NumberGameStateOutBorders();

		virtual void render();
		virtual void processEvents();
		virtual void update();
	};
}