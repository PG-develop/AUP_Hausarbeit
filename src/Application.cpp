#include "Application.hpp"

// States
#include "IntroState.hpp"
#include "MainState.hpp"
#include "GameState.hpp"
#include "SetupState.hpp"
#include "LeaderboardState.hpp"

namespace AUP_HA 
{
	/*
	* @Constructor
	* 
	* @description Instanz des StateManager instanziieren und States registrieren
	*/
	Application::Application()
	{
		// Instanz - StateManager instanziieren 
		std::unique_ptr<StateManager> stateManager(new StateManager());
		mStateManager = std::move(stateManager);

		// States für den StateManager registrieren
		RegisterStates();

		mStateManager->changeState(States::INTRO);
	}

	/*
	* @Destructor
	*/
	Application::~Application()
	{
	}

	/*
	* @description Steuerung des Programmflusses
	*/
	void Application::run()
	{
		while (mStateManager->hasActiveState())
		{
			render();
			processEvents();
			update();
		}
	}

	/*
	*
	*/
	void Application::render()
	{
		mStateManager->render();
	}

	/*
	*
	*/
	void Application::processEvents()
	{
		mStateManager->processEvents();
	}

	/*
	*
	*/
	void Application::update()
	{
		mStateManager->update();
	}

	/*
	* @description Registriert States in der Statefactory
	*/
	void Application::RegisterStates()
	{
		mStateManager->registerStates<IntroState>(States::INTRO);
		mStateManager->registerStates<MainState>(States::MAIN);
		mStateManager->registerStates<GameState>(States::GAME);
		mStateManager->registerStates<SetupState>(States::SETUP);
		mStateManager->registerStates<LeaderboardState>(States::LEADERBOARD);
	}
}
