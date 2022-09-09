#include <iostream>

#include "../include/SetupState.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	SetupState::SetupState(StateManager& stateManager) 
		: State(stateManager)
		, mMenu( )
	{
		// Menü initialisieren
		registerMenu();
		mLimits = std::make_pair(1, mMenu.count());
	}

	SetupState::~SetupState()
	{
	}

	void SetupState::render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		std::cout << "===============" << std::endl << std::endl;

		std::cout << "    Einstellungen" << std::endl;
		std::cout << "[1] Spieleinstellungen" << std::endl;
		std::cout << "[2] Bestenliste zuruecksetzen" << std::endl;
		std::cout << "[3] Zurueck" << std::endl << std::endl;

		std::cout << "Auswahl: ";
	
		// TODO: Mehrere Einstellmöglichkeiten überprüfen
	}

	void SetupState::processEvents()
	{
		std::cin >> mUserinput;
		Utilities::ClearInputStream();
	}

	void SetupState::update()
	{
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

	void SetupState::registerMenu()
	{
		mMenu.registerMenu(SetupMenu::GAMESETUP, [&]() {
			onGameSetup();
			});
		mMenu.registerMenu(SetupMenu::CLEAR, [&]() {
			onClear();
			});
		mMenu.registerMenu(SetupMenu::EXIT, [&]() {
			onExit();
			});
	}
	void SetupState::onGameSetup()
	{
		requestChange(States::GAMESETUP_GAME);
	}
	void SetupState::onClear()
	{
		requestChange(States::GAMESETUP_CLEAR);
	}
	void SetupState::onExit()
	{
		requestChange(States::MAIN);
	}
}