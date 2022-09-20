#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateNoNumber : public NumberGameState
	{
	public:
		NumberGameStateNoNumber(NumberGameStateManager& manager);
		virtual ~NumberGameStateNoNumber();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}