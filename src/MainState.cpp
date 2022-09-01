#include "MainState.hpp"
#include "Utilities.hpp"

namespace AUP_HA
{
	MainState::MainState(StateManager& stateManager)
		: State(stateManager)
		, mMenu()
	{
		registerMenu();
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
		std::cout << "[2] Optionen" << std::endl;
		std::cout << "[3] Highscoreliste" << std::endl;
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
		auto limits = std::make_pair(1, 4);

		// 
		auto userInput = Utilities::ParseStringToIntWithLimits(mUserinput, limits);

		// Prüfe auf valide Benutzereingabe
		if (userInput)
		{
			// TODO: Handler aus dem Menu aufrufen
			std::cout << "Erfolgreiche Eingabe: " << *userInput << std::endl;
		}
		else
		{
			// TODO: Eingabe inkorrekt, Nachricht an den Benutzer und nächster Tik
			std::cout << "Invalide Eingabe. " << std::endl;
		}
	}

	void MainState::registerMenu()
	{
		mMenu.registerMenu(MainMenu::GAME, std::bind(&MainState::onGame, this));
		mMenu.registerMenu(MainMenu::SETUP, std::bind(&MainState::onSetup, this));
		mMenu.registerMenu(MainMenu::LEADERBOARD, std::bind(&MainState::onLeaderboard, this));
		mMenu.registerMenu(MainMenu::EXIT, std::bind(&MainState::onExit, this));	
	}

	void MainState::onGame()
	{
		requestChange(States::GAME);
	}

	void MainState::onSetup()
	{
		requestChange(States::SETUP);
	}

	void MainState::onLeaderboard()
	{
		requestChange(States::LEADERBOARD);
	}

	void MainState::onExit()
	{
		requestChange(States::NONE);
	}
}
