#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	/**
	* @class NumberGameStateAskNewGame
	* @brief STATE_7
	* 
	* Abfrage, ob ein neues Spiel gestartet werden soll.
	*/
	class NumberGameStateAskNewGame : public NumberGameState
	{
	public:
		NumberGameStateAskNewGame(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateAskNewGame();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();
	};
}