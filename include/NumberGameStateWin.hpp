#pragma once

#include <vector>

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	/**
	* @class NumberGameStateWin
	* @brief STATE_5
	*
	* Der Benutzer hat die gesuchte Zahl gefunden.
	*/
	class NumberGameStateWin : public NumberGameState
	{
	public:
		NumberGameStateWin(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateWin();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}