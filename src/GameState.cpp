#include "../include/GameState.hpp"

namespace AUP_HA
{
	GameState::GameState(StateManager& stateManager) : State(stateManager)
	{
	}

	GameState::~GameState()
	{
	}

	void GameState::render()
	{
		std::cout << "GameState" << std::endl;
	}

	void GameState::processEvents()
	{
	}

	void GameState::update()
	{
	}
}