#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	/**
	* @class NumberGameStateNoNumber
	* @brief STATE_3
	*
	* Der Benutzer hat keine gültige Nummer eingetippt.
	* Der Benutzer wird aufgefordert, eine Nummer einzugeben.
	*/
	class NumberGameStateNoNumber : public NumberGameState
	{
	public:
		NumberGameStateNoNumber(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateNoNumber();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}