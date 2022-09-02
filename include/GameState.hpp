#pragma once

#include <iostream>
#include <memory>

#include "../include/State.hpp"
#include "../include/UserRepository.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	class GameState : public State
	{
	public:
		GameState(StateManager& stateManager);
		~GameState();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		void registerStates();

	private:
		std::unique_ptr<UserRepository>			mUserRepository;
		std::unique_ptr<NumberGameStateManager> mGameStateManager;

		User mUser;
	};
}