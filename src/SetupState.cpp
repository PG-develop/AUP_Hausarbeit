#include <iostream>

#include "../include/SetupState.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	SetupState::SetupState(StateManager& stateManager) 
		: State(stateManager)
		, mMenu( )
	{
		registerMenu();
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
		std::cout << "[4] Zurueck" << std::endl << std::endl;

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

	void SetupState::registerMenu()
	{

	}
}