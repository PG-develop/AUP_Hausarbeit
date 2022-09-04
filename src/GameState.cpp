#include "../include/GameState.hpp"
#include "../include/StatesIdentifier.hpp"

#include "../include/NumberGameStateName.hpp"
#include "../include/NumberGameStateNormal.hpp"
#include "../include/NumberGameStateNoNumber.hpp"
#include "../include/NumberGameStateOutBorders.hpp"
#include "../include/NumberGameStateWin.hpp"

namespace AUP_HA
{
	GameState::GameState(StateManager& stateManager) : State(stateManager)
	{
		mUserRepository = std::make_unique<UserRepository>();
		mGame = std::make_unique<Game>();
		mGameStateManager = std::make_unique<NumberGameStateManager>(*(mUserRepository.get()), *(mGame.get()));

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
		mGameStateManager->registerStates<NumberGameStateNormal>(GameStates::STATE_2);
		mGameStateManager->registerStates<NumberGameStateNoNumber>(GameStates::STATE_3);
		mGameStateManager->registerStates<NumberGameStateOutBorders>(GameStates::STATE_4);
		mGameStateManager->registerStates<NumberGameStateWin>(GameStates::STATE_5);
	}
}