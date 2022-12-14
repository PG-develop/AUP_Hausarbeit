#include "../include/Application.hpp"
#include "../include/StateManager.hpp"

// States
#include "../include/IntroState.hpp"
#include "../include/MainState.hpp"
#include "../include/GameState.hpp"
#include "../include/SetupState.hpp"
#include "../include/LeaderboardState.hpp"
#include "../include/SetupGameState.hpp"

namespace AUP_HA 
{
	/**
	* @brief Konstruktor
	* 
	* Instanz des StateManager instanziieren und States registrieren.
	*/
	Application::Application()
	{
		// Instanz - StateManager instanziieren 
		std::unique_ptr<StateManager> stateManager(new StateManager());
		mStateManager = std::move(stateManager);

		// States f?r den StateManager registrieren
		registerStates();

		// IntroState als aktiven State festlegen
		mStateManager->changeState(States::INTRO);
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	Application::~Application()
	{
	}

	/**
	* @brief Steuerung des Programmflusses
	* 
	* Solange ein State aktiv ist, werden fortlaufend Ticks durchgef?hrt.
	*/
	void Application::Run()
	{
		// Solange ein State aktiv ist, bleibt der 
		// Programmfluss erhalten und es kommt zum n?chsten Tick.
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
		mStateManager->Render();
	}

	/**
	* @brief Benutzer- oder/und Eventeingabe
	*/
	void Application::processEvents()
	{
		mStateManager->ProcessEvents();
	}

	/**
	* @brief Durchf?hung der Logic
	*/
	void Application::update()
	{
		mStateManager->Update();
	}

	/**
	* @brief Registriert States in der Statefactory
	*/
	void Application::registerStates()
	{
		mStateManager->registerStates<IntroState>(States::INTRO);
		mStateManager->registerStates<MainState>(States::MAIN);
		mStateManager->registerStates<GameState>(States::GAME);
		mStateManager->registerStates<SetupState>(States::SETUP);
		mStateManager->registerStates<LeaderboardState>(States::LEADERBOARD);
		mStateManager->registerStates<SetupGameState>(States::GAMESETUP_GAME);
	}
}
