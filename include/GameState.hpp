#pragma once

#include <iostream>
#include <memory>

#include "../include/State.hpp"
#include "../include/UserRepository.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Game.hpp"

namespace AUP_HA
{
	/**
	* @class GameState
	* @brief State für die Spielsession
	*/
	class GameState : public State
	{
	public:
		GameState(StateManager& stateManager_p);
		~GameState();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		void registerStates();

	private:
		std::unique_ptr<UserRepository>			mUserRepository;	/**< UserRepository */
		std::unique_ptr<NumberGameStateManager> mGameStateManager;	/**< NumberGameStateManager */
		std::unique_ptr<Game>					mGame;				/**< Game */
	};
}