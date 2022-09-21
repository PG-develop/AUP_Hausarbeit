#include "../include/MainState.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Instanziierung des Menu
	*/
	MainState::MainState(StateManager& stateManager)
		: State(stateManager)
		, mMenu()
	{
		// Menüregistrierung
		registerMenu();

		// Limitierung für die Menüeingabe
		mLimits = std::make_pair(1, mMenu.Count());
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	MainState::~MainState()
	{
	}

	/**
	* @brief Anzeige des States
	* 
	* Gibt die Menüstruktur aus.
	*/
	void MainState::Render()
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

	/**
	* @brief Benutztereingabe
	*/
	void MainState::ProcessEvents()
	{
		std::cin >> mUserinput;
		Utilities::ClearInputStream();
	}

	/**
	* @brief Ausführung der Statelogic
	*/
	void MainState::Update()
	{
		// Eingabe des Benutzers parsen mit Grenzen
		auto userInput = Utilities::ParseStringToIntWithLimits(mUserinput, mLimits);

		// Prüfe auf valide Benutzereingabe
		if (userInput)
		{
			// Wähle Menüpunkt aus
			mMenu.SelectMenuItem(*userInput);
		}

		// Benutzereingabe war nicht korrekt
		else
		{
			std::cout << "Invalide Eingabe. " << std::endl;
		}
	}

	/**
	* @brief Registrierung der Menühandlers 
	*/
	void MainState::registerMenu()
	{
		mMenu.RegisterMenu(MainMenu::GAME, 
			[&]() 
			{
				onGame(); 
			}); 

		mMenu.RegisterMenu(MainMenu::SETUP, 
			[&]() 
			{
				onSetup(); 
			});

		mMenu.RegisterMenu(MainMenu::LEADERBOARD,
			[&]()
			{
				onLeaderboard();
			});

		mMenu.RegisterMenu(MainMenu::EXIT,
			[&]()
			{
				onExit();
			});
	}

	/**
	* @brief Handler für den Menüpunkt [1] Spielen
	* 
	* Wechsel zum GameState
	*/
	void MainState::onGame()
	{
		requestChange(States::GAME);
	}

	/**
	* @brief Handler für den Menüpunkt [2] Einstellungen
	* 
	* Wechsel zum SetupState
	*/
	void MainState::onSetup()
	{
		requestChange(States::SETUP);
	}

	/**
	* @brief Handler für den Menüpunkt [3] Bestenliste
	* 
	* Wechsel zum LeaderboardState
	*/
	void MainState::onLeaderboard()
	{
		requestChange(States::LEADERBOARD);
	}

	/**
	* @brief Handler für den Menüpunkt [4] Beenden
	* 
	* Anwendung wird beendet
	*/
	void MainState::onExit()
	{
		requestChange(States::NONE);
	}
}
