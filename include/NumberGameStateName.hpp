#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	/**
	* @class NumberGameStateName
	* @brief STATE_1
	*
	* Der Benutzer wird aufgefordert seinen Namen einzutragen.
	*/
	class NumberGameStateName : public NumberGameState
	{
	public:
		NumberGameStateName(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateName();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}