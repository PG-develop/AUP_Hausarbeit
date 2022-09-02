#pragma once

#include <iostream>
#include <memory>

#include "../include/State.hpp"
#include "../include/UserRepository.hpp"


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
		std::unique_ptr<UserRepository>	mUserRepository;
	};
}