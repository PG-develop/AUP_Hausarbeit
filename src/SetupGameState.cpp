#include <iostream>

#include "../include/SetupGameState.hpp"
#include "../include/SetupRepository.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Erstelle das SetupRepository und initialisiere Menü für die Auswahl
	* 
	* @param [stateManager_p] StateManager 
	*/
	SetupGameState::SetupGameState(StateManager& stateManager_p) : State(stateManager_p), mUserinput(), mMenu()
	{
		// Erstelle SetupRepository
		mSetupRepository = std::make_unique<SetupRepository>();

		// Menüregistrierung
		registerMenu();
		mLimits = std::make_pair(1, mMenu.Count());
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	SetupGameState::~SetupGameState()
	{
	}

	/**
	* @brief Anzeige des States
	*
	* Gibt die Menüstruktur aus.
	*/
	void SetupGameState::Render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		std::cout << "===============" << std::endl << std::endl;

		std::cout << "    Spieleinstellungen" << std::endl;
		std::cout << "[1] Maximale Anzahl an Versuchen: " << mSetupRepository->GetAmountOfChoices() << std::endl;
		std::cout << "[2] Zahlenstreureichweite: " << mSetupRepository->GetMaxRange() << std::endl;
		std::cout << "[3] Zurueck" << std::endl << std::endl;

		std::cout << "Auswahl: ";
	}

	/**
	* @brief Benutztereingabe
	*/
	void SetupGameState::ProcessEvents()
	{
		std::cin >> mUserinput;
		Utilities::ClearInputStream();
	}

	/**
	* @brief Ausführung der Statelogic
	*/
	void SetupGameState::Update()
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
	void SetupGameState::registerMenu()
	{
		mMenu.RegisterMenu(SETUP_GAMESETUP::GAMESETUP_CHANGE_AMOUNT_OF_CHOICES, 
			[&]() 
			{
				onChangeAmountOfChoices();
			});
		mMenu.RegisterMenu(SETUP_GAMESETUP::GAMESETUP_CHANGE_MAX_RANGE, 
			[&]() 
			{
				onChangeMaxRange();
			});
		mMenu.RegisterMenu(SETUP_GAMESETUP::EXIT, 
			[&]() 
			{
				onExit();
			});
	}

	/**
	* @brief Handler für den Menüpunkt [1] Anzahl der Versuche 
	*
	* Ändert die maximale Anzahl der Versuche. Wenn die Anzahl
	* gleich 0 ist, ist die Anzahl unbegrenzt.
	*/
	void SetupGameState::onChangeAmountOfChoices()
	{
		std::optional<std::int32_t> input;

		// Vereinfachte Eingabe, um keinen weiteren State zu implementieren.
		// Solange die Zahl nicht größer 0 ist, wiederhole die Frage.
		do
		{
			// Solange keine Zahl eingegeben wurde, wiederhole die Frage.
			do
			{
				std::cout << "Anzahl der Versuche aender: [" << mSetupRepository->GetAmountOfChoices() << "] ";
				std::cin >> mUserinput;

				input = Utilities::ParseStringToInt(mUserinput);
			} while (!input);
		} while (*input < 0);

		// Verändere den Setupeintrag "Amount of Choices" im SetupRepository
		mSetupRepository->SetAmountOfChoices(*input);

		// Wechsle den State auf GAMESETUP_GAME
		requestChange(States::GAMESETUP_GAME);
	}

	/**
	* @brief Handler für den Menüpunkt [2] Streureichweite
	*
	* Ändert die Streureichweite.
	*/
	void SetupGameState::onChangeMaxRange()
	{
		std::optional<std::int32_t> input;

		// Vereinfachte Eingabe, um keinen weiteren State zu implementieren.
		// Solange die Zahl nicht größer 0 ist, wiederhole die Frage.
		do
		{
			// Solange keine Zahl eingegeben wurde, wiederhole die Frage.
			do
			{
				std::cout << "Zahlenstreureichweite aender: [" << mSetupRepository->GetMaxRange() << "] ";
				std::cin >> mUserinput;

				input = Utilities::ParseStringToInt(mUserinput);
			} while (!input);
		} while (*input < 0);

		// Verändere den Setupeintrag "Amount of Choices" im SetupRepository
		mSetupRepository->SetMaxRange(*input);

		requestChange(States::GAMESETUP_GAME);
	}

	/**
	* @brief Handler für den Menüpunkt [3] Zurück
	*
	* Ändert den State auf SETUP
	*/
	void SetupGameState::onExit()
	{
		requestChange(States::SETUP);
	}
}