#include <conio.h>

#include "../include/IntroState.hpp"

namespace AUP_HA 
{
	IntroState::IntroState(StateManager& stateManager) : State(stateManager)
	{
	}

	IntroState::~IntroState()
	{
	}

	void IntroState::render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		std::cout << "===============" << std::endl << std::endl;

		std::cout << "Autor: Patrick Gehrt" << std::endl;
		std::cout << "Matrikelnummer: 214849" << std::endl;
		std::cout << "Dozent: Prof. Dr. Froese" << std::endl << std::endl;

		std::cout << "Weiter mit einer beliebigen Taste..." << std::endl;
	}

	void IntroState::processEvents()
	{
		while (!_kbhit());
		_getch();
	}

	void IntroState::update()
	{
		requestChange(States::MAIN);
	}
}