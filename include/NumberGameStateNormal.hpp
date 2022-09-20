#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	class NumberGameStateNormal : public NumberGameState
	{
	public:
		NumberGameStateNormal(NumberGameStateManager& manager);
		virtual ~NumberGameStateNormal();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}