#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	// Vorwärtsdeklaration
	class UserRepository;


	/**
	* @class NumberGameStateCheatWin
	* @brief STATE_9
	* 
	* Das Spiel wird sofort gewonnen.
	*/
	class NumberGameStateCheatWin : public NumberGameState
	{
	public:
		NumberGameStateCheatWin(NumberGameStateManager& manager_p);
		virtual ~NumberGameStateCheatWin();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		UserRepository* mUserRepository; /**< Referenz auf das UserRepository */
	};
}