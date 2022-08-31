#include "MainState.hpp"
#include "Utilities.hpp"

namespace AUP_HA
{
	MainState::MainState(StateManager& stateManager) : State(stateManager)
	{
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
