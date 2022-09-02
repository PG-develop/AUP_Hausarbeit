#include "../include/GameState.hpp"
#include "../include/StatesIdentifier.hpp"

#include "../include/NumberGameStateName.hpp"

namespace AUP_HA
{
	GameState::GameState(StateManager& stateManager) : State(stateManager)
	{
		mUserRepository = std::make_unique<UserRepository>();
		mGameStateManager = std::make_unique<NumberGameStateManager>(*(mUserRepository.get()));

		registerStates();

		mGameStateManager->changeState(GameStates::ID::FIRST);
	}

	GameState::~GameState()
	{
	}

	void GameState::render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		mGameStateManager->render();
	}

	void GameState::processEvents()
	{
		mGameStateManager->processEvents();
	}

	void GameState::update()
	{
		mGameStateManager->update();
	}

	void GameState::registerStates()
	{
		mGameStateManager->registerStates<NumberGameStateName>(GameStates::FIRST);
	}
}