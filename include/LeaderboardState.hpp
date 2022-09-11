#pragma once

#include <iostream>
#include <memory>

#include "../include/State.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{

	/**
	* @brief State für die Bestenliste
	*/
	class LeaderboardState : public State
	{
	public:
		LeaderboardState(StateManager& stateManager);
		~LeaderboardState();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		std::unique_ptr<UserRepository> mUserRepository; /**< UserRepository */
	};
}