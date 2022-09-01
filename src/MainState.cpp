#include "../include/MainState.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	MainState::MainState(StateManager& stateManager)
		: State(stateManager)
		, mMenu()
	{
		registerMenu();
		mLimits = std::make_pair(1, mMenu.count());
	}

	MainState::~MainState()
	{
	}

	void MainState::render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		std::cout << "===============" << std::endl << std::endl;

		std::cout << "    Menu" << std::endl;
		std::cout << "[1] Starte Spiel" << std::endl;
		std::cout << "[2] Einstellungen" << std::endl;
		std::cout << "[3] Bestenliste" << std::endl;
		std::cout << "[4] Beenden" << std::endl << std::endl;

		std::cout << "Auswahl: ";
	}

	void MainState::processEvents()
	{
		std::cin >> mUserinput;
		Utilities::ClearInputStream();
	}

	void MainState::update()
	{
		// Limits für die Menueingabe für Menuitem 1 - 4
		//auto limits = std::make_pair(1, 4);

		// Eingabe des Benutzers parsen
		auto userInput = Utilities::ParseStringToIntWithLimits(mUserinput, mLimits);

		// Prüfe auf valide Benutzereingabe
		if (userInput)
		{
			// Wähle Menüpunkt aus
			mMenu.selectMenuItem(*userInput);
		}
		else
		{
			// TODO: Eingabe inkorrekt, Nachricht an den Benutzer und nächster TIK
			std::cout << "Invalide Eingabe. " << std::endl;
		}
	}

	/**
	* @brief Registrierung der Menühandlers 
	*/
	void MainState::registerMenu()
	{
		mMenu.registerMenu(MainMenu::GAME, std::bind(&MainState::onGame, this));
		mMenu.registerMenu(MainMenu::SETUP, std::bind(&MainState::onSetup, this));
		mMenu.registerMenu(MainMenu::LEADERBOARD, std::bind(&MainState::onLeaderboard, this));
		mMenu.registerMenu(MainMenu::EXIT, std::bind(&MainState::onExit, this));	
	}

	/**
	* @brief Handler für den Menüpunkt [1] Spielen
	*/
	void MainState::onGame()
	{
		requestChange(States::GAME);
	}

	/**
	* @brief Handler für den Menüpunkt [2] Einstellungen
	*/
	void MainState::onSetup()
	{
		requestChange(States::SETUP);
	}

	/**
	* @brief Handler für den Menüpunkt [1] Bestenliste
	*/
	void MainState::onLeaderboard()
	{
		requestChange(States::LEADERBOARD);
	}

	/**
	* @brief Handler für den Menüpunkt [1] Beenden
	*/
	void MainState::onExit()
	{
		requestChange(States::NONE);
	}
}
