#include <iostream>

#include "../include/SetupState.hpp"
#include "../include/Utilities.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Erstelle das SetupRepository und initialisiere Menü für die Auswahl
	*/
	SetupState::SetupState(StateManager& stateManager_p) 
		: State(stateManager_p)
		, mMenu( )
	{
		// Menü initialisieren
		registerMenu();
		mLimits = std::make_pair(1, mMenu.Count());
		mUserRepository = std::make_unique<UserRepository>();
	}

	/**
	* brief Destruktor
	* 
	* Keine Funktion
	*/
	SetupState::~SetupState()
	{
	}

	/**
	* @brief Anzeige des States
	*
	* Gibt die Menüstruktur aus.
	*/
	void SetupState::Render()
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

	/**
	* @brief Benutztereingabe
	*/
	void SetupState::ProcessEvents()
	{
		std::cin >> mUserinput;
		Utilities::ClearInputStream();
	}

	/**
	* @brief Ausführung der Statelogic
	*/
	void SetupState::Update()
	{
		// Eingabe des Benutzers parsen
		auto userInput = Utilities::ParseStringToIntWithLimits(mUserinput, mLimits);

		// Prüfe auf valide Benutzereingabe
		if (userInput)
		{
			// Wähle Menüpunkt aus
			mMenu.SelectMenuItem(*userInput);
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
	void SetupState::registerMenu()
	{
		mMenu.RegisterMenu(SetupMenu::GAMESETUP, [&]() {
			onGameSetup();
			});
		mMenu.RegisterMenu(SetupMenu::CLEAR, [&]() {
			onClear();
			});
		mMenu.RegisterMenu(SetupMenu::EXIT, [&]() {
			onExit();
			});
	}

	/**
	* @brief Handler für den Menüpunkt [1] Wechsel zu den Spieleinstellungen
	*/
	void SetupState::onGameSetup()
	{
		requestChange(States::GAMESETUP_GAME);
	}

	/**
	* @brief Handler für den Menüpunkt [2] Bestenliste löschen
	*/
	void SetupState::onClear()
	{
		// Abfrage, ob Benutzer Sicher ist
		do
		{
			std::cout << "Moechten Sie wirklich die Bestenliste loeschen? Die Daten koennen nicht wiederhergestellt werden!" << std::endl;
			std::cout << "[J]a oder [N]ein: ";

			std::cin >> mUserinput;
		} while (mUserinput != "j" && mUserinput != "n");

		// Mit "j" wird das löschen der Bestenliste bestätigt
		if (mUserinput == "j")
		{
			mUserRepository->ClearRepository();
		}
	}

	/**
	* @brief Handler für den Menüpunkt [3] Wechsel zum MAIN State
	*/
	void SetupState::onExit()
	{
		requestChange(States::MAIN);
	}
}