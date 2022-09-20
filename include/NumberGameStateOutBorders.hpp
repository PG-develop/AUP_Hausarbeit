#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateOutBorders : public NumberGameState
	{
	public:
		NumberGameStateOutBorders(NumberGameStateManager& manager);
		virtual ~NumberGameStateOutBorders();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}