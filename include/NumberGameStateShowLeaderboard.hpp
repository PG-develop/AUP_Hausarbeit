#pragma once

#include "../include/NumberGameState.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{
	/**
	* @class STATE_3
	*
	* Der Benutzer hat keine gültige Nummer eingetippt.
	* Der Benutzer wird aufgefordert, eine Nummer einzugeben.
	*/
	class NumberGameStateShowLeaderboard : public NumberGameState
	{
	public:
		NumberGameStateShowLeaderboard(NumberGameStateManager& manager);
		virtual ~NumberGameStateShowLeaderboard();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		UserRepository* mUserRepository;	/**< Referenz auf das UserRepository */
	};
}