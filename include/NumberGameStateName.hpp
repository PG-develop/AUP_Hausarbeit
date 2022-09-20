#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateName : public NumberGameState
	{
	public:
		NumberGameStateName(NumberGameStateManager& manager);
		virtual ~NumberGameStateName();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}