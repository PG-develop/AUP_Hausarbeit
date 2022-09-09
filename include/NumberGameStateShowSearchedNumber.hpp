#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateShowSearchedNumber : public NumberGameState
	{
	public:
		NumberGameStateShowSearchedNumber(NumberGameStateManager& manager);
		virtual ~NumberGameStateShowSearchedNumber();

		virtual void render();
		virtual void processEvents();
		virtual void update();
	};
}