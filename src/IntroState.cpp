#include <conio.h>

#include "../include/IntroState.hpp"

namespace AUP_HA 
{
	/**
	* @brief Konstruktor 
	* 
	* Übergibt seinen StateManager an die Basisklasse
	*/
	IntroState::IntroState(StateManager& stateManager) : State(stateManager)
	{
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	IntroState::~IntroState()
	{
	}

	/**
	* @brief Darstellungsimplementierung
	*/
	void IntroState::Render()
	{
		std::cout << "Zahlenratespiel" << std::endl;
		std::cout << "===============" << std::endl << std::endl;

		std::cout << "Autor: Patrick Gehrt" << std::endl;
		std::cout << "Matrikelnummer: 214849" << std::endl;
		std::cout << "Kursnummer: I_ET_B_026" << std::endl;
		std::cout << "Dozent: Prof. Dr. Froese" << std::endl << std::endl;

		std::cout << "Weiter mit einer beliebigen Taste..." << std::endl;
	}

	/**
	* @brief Benutzer- oder/und Eventeingabe
	* 
	* Wartet nur auf eine beliebige Eingabe vom Benutzer
	*/
	void IntroState::ProcessEvents()
	{
		while (!_kbhit());
		_getch();
	}

	/**
	* @brief Logikausführung
	* 
	* Wechsel zum MainState
	*/
	void IntroState::Update()
	{
		requestChange(States::MAIN);
	}
}