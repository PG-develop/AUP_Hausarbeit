#include "../include/GameState.hpp"
#include "../include/StatesIdentifier.hpp"

#include "../include/NumberGameStateName.hpp"
#include "../include/NumberGameStateNormal.hpp"
#include "../include/NumberGameStateNoNumber.hpp"
#include "../include/NumberGameStateOutBorders.hpp"
#include "../include/NumberGameStateWin.hpp"
#include "../include/NumberGameStateShowLeaderboard.hpp"
#include "../include/NumberGameStateAskNewGame.hpp"
#include "../include/NumberGameStateShowSearchedNumber.hpp"
#include "../include/NumberGameStateCheatWin.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Initialsisierung der Member\n
	* Registrierung der Spielstates
	* 
	* @param [stateManager_p] StateManager 
	*/
	GameState::GameState(StateManager& stateManager_p) : State(stateManager_p)
	{
		mUserRepository = std::make_unique<UserRepository>();
		mGame = std::make_unique<Game>();
		mGameStateManager = std::make_unique<NumberGameStateManager>(*(mUserRepository.get()), *(mGame.get()));

		registerStates();

		// Handler für das Spielende definieren
		mGameStateManager->RegisterEndGameHandler([&]() {
			requestChange(States::MAIN);
		});

		// Ersten Spielstate definieren
		mGameStateManager->ChangeState(GameStates::ID::STATE_1);
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	GameState::~GameState()
	{
	}

	/**
	* @brief Darstellungsmethode
	* 
	* Führt die Rendermethoden des NumberGameStateManagers aus
	*/
	void GameState::Render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		mGameStateManager->Render();
	}

	/**
	* @brief Benutzer- oder/und Eventeingabe
	*
	* Führt die ProcessEventsmethode des NumberGameStateManagers aus
	*/
	void GameState::ProcessEvents()
	{
		mGameStateManager->ProcessEvents();
	}

	/**
	* @brief Benutzer- oder/und Eventeingabe
	*
	* Führt die Updatemethode des NumberGameStateManagers aus
	*/
	void GameState::Update()
	{
		mGameStateManager->Update();
	}

	/**
	* @brief Registrierung der NumberGameStates
	*/
	void GameState::registerStates()
	{
		mGameStateManager->RegisterStates<NumberGameStateName>(GameStates::STATE_1);
		mGameStateManager->RegisterStates<NumberGameStateNormal>(GameStates::STATE_2);
		mGameStateManager->RegisterStates<NumberGameStateNoNumber>(GameStates::STATE_3);
		mGameStateManager->RegisterStates<NumberGameStateOutBorders>(GameStates::STATE_4);
		mGameStateManager->RegisterStates<NumberGameStateWin>(GameStates::STATE_5);
		mGameStateManager->RegisterStates<NumberGameStateShowLeaderboard>(GameStates::STATE_6);
		mGameStateManager->RegisterStates<NumberGameStateAskNewGame>(GameStates::STATE_7);
		mGameStateManager->RegisterStates<NumberGameStateShowSearchedNumber>(GameStates::STATE_8);
		mGameStateManager->RegisterStates<NumberGameStateCheatWin>(GameStates::STATE_9);
	}
}