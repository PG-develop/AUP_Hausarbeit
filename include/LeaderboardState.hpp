#pragma once

#include <iostream>
#include <memory>

#include "../include/State.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{

	/**
	* @class LeaderboardState
	* @brief State für die Bestenliste
	*/
	class LeaderboardState : public State
	{
	public:
		LeaderboardState(StateManager& stateManager_p);
		~LeaderboardState();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		std::unique_ptr<UserRepository> mUserRepository; /**< UserRepository */
	};
}