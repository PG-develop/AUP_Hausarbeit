#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateNoNumber : public NumberGameState
	{
	public:
		NumberGameStateNoNumber(NumberGameStateManager& manager);
		virtual ~NumberGameStateNoNumber();

		virtual void render();
		virtual void processEvents();
		virtual void update();
	};
}