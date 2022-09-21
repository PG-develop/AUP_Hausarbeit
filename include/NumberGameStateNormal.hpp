#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	/**
	* @class STATE_2
	*
	* Vorherige Eingabe war korrekt.
	* Der Benutzer wird aufgefordert, eine Nummer einzugeben.
	*/
	class NumberGameStateNormal : public NumberGameState
	{
	public:
		NumberGameStateNormal(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateNormal();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}