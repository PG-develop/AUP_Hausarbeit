#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	/**
	* @class NumberGameStateShowSearchedNumber
	* @brief STATE_8
	*
	* Sonderfunktion
	* Dem Benutzer wird die gesuchte Zahl angezeigt.
	* Der Spielfluss geht normal weiter.
	*/
	class NumberGameStateShowSearchedNumber : public NumberGameState
	{
	public:
		NumberGameStateShowSearchedNumber(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateShowSearchedNumber();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}