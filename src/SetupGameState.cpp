#include <iostream>

#include "../include/SetupGameState.hpp"
#include "../include/SetupRepository.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	SetupGameState::SetupGameState(StateManager& stateManager) : State(stateManager), mUserinput(), mMenu()
	{
		mSetupRepository = std::make_unique<SetupRepository>();

		registerMenu();
		mLimits = std::make_pair(1, mMenu.count());
	}
	SetupGameState::~SetupGameState()
	{
	}
	void SetupGameState::Render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		std::cout << "===============" << std::endl << std::endl;

		std::cout << "    Spieleinstellungen" << std::endl;
		std::cout << "[1] Maximale Anzahl an Versuchen: " << mSetupRepository->getAmountOfChoices() << std::endl;
		std::cout << "[2] Zahlenstreureichweite: " << mSetupRepository->getMaxRange() << std::endl;
		std::cout << "[3] Zurueck" << std::endl << std::endl;

		std::cout << "Auswahl: ";
	}
	void SetupGameState::ProcessEvents()
	{
		std::cin >> mUserinput;
		Utilities::ClearInputStream();
	}
	void SetupGameState::Update()
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
	void SetupGameState::registerMenu()
	{
		mMenu.registerMenu(SETUP_GAMESETUP::GAMESETUP_CHANGE_AMOUNT_OF_CHOICES, [&]() {
			onChangeAmountOfChoices();
			});
		mMenu.registerMenu(SETUP_GAMESETUP::GAMESETUP_CHANGE_MAX_RANGE, [&]() {
			onChangeMaxRange();
			});
		mMenu.registerMenu(SETUP_GAMESETUP::EXIT, [&]() {
			onExit();
			});
	}
	void SetupGameState::onChangeAmountOfChoices()
	{
		std::optional<int> input;

		// Solange die Zahl nicht größer 0 ist, wiederhole die Frage.
		do
		{
			// Solange keine Zahl eingegeben wurde, wiederhole die Frage.
			do
			{
				std::cout << "Anzahl der Versuche aender: [" << mSetupRepository->getAmountOfChoices() << "] ";
				std::cin >> mUserinput;

				input = Utilities::ParseStringToInt(mUserinput);
			} while (!input);
		} while (*input < 0);

		// Verändere den Setupeintrag "Amount of Choices"
		mSetupRepository->setAmountOfChoices(*input);

		requestChange(States::GAMESETUP_GAME);
	}
	void SetupGameState::onChangeMaxRange()
	{
		std::optional<int> input;

		// Solange die Zahl nicht größer 0 ist, wiederhole die Frage.
		do
		{
			// Solange keine Zahl eingegeben wurde, wiederhole die Frage.
			do
			{
				std::cout << "Zahlenstreureichweite aender: [" << mSetupRepository->getMaxRange() << "] ";
				std::cin >> mUserinput;

				input = Utilities::ParseStringToInt(mUserinput);
			} while (!input);
		} while (*input < 0);

		// Verändere den Setupeintrag "Amount of Choices"
		mSetupRepository->setMaxRange(*input);

		requestChange(States::GAMESETUP_GAME);
	}
	void SetupGameState::onExit()
	{
		requestChange(States::SETUP);
	}
}