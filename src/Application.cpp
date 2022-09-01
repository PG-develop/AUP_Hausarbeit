#include "../include/Application.hpp"

// States
#include "../include/IntroState.hpp"
#include "../include/MainState.hpp"
#include "../include/GameState.hpp"
#include "../include/SetupState.hpp"
#include "../include/LeaderboardState.hpp"

namespace AUP_HA 
{
	/**
	* @brief Instanz des StateManager instanziieren und States registrieren
	*/
	Application::Application()
	{
		// Instanz - StateManager instanziieren 
		std::unique_ptr<StateManager> stateManager(new StateManager());
		mStateManager = std::move(stateManager);

		// States für den StateManager registrieren
		RegisterStates();

		// IntroState als aktiven State festlegen
		mStateManager->changeState(States::INTRO);
	}

	/**
	* @Destructor
	*/
	Application::~Application()
	{
	}

	/**
	* @bief Steuerung des Programmflusses (Ticks),
	*		jeder Durchgang ist ein Tick.
	*/
	void Application::run()
	{
		// Solange ein State aktiv ist, bleibt der 
		// Programmfluss erhalten und es kommt zum nächsten Tick.
		while (mStateManager->hasActiveState())
		{
			render();
			processEvents();
			update();
		}
	}

	/**
	* @brief Darstellung 
	*/
	void Application::render()
	{
		mStateManager->render();
	}

	/**
	* @brief Benutzer- oder/und Eventeingabe
	*/
	void Application::processEvents()
	{
		mStateManager->processEvents();
	}

	/**
	* @brief Durchfühung der Logic
	*/
	void Application::update()
	{
		mStateManager->update();
	}

	/**
	* @brief Registriert States in der Statefactory
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
