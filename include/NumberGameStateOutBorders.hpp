#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	/**
	* @class NumberGameStateOutBorders
	* @brief STATE_4
	*
	* Die Eingabe des Benutzers war auﬂerhalb der Grenzen.
	* Der Benutzer wird aufgefordert, eine Nummer einzugeben.
	*/
	class NumberGameStateOutBorders : public NumberGameState
	{
	public:
		NumberGameStateOutBorders(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateOutBorders();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}