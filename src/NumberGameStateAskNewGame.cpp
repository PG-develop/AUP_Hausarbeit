#include "../include/NumberGameStateAskNewGame.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Laden der Übergangsbedingungen: NG
	* 
	* @param [manager_p] NumberGameStateManager 
	*/
	NumberGameStateAskNewGame::NumberGameStateAskNewGame(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
	{
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::NG));
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	NumberGameStateAskNewGame::~NumberGameStateAskNewGame()
	{
	}

	/**
	* @brief Spielanzeige
	* 
	* Es wird gefragt, ob ein neues Spiel gestartet werden soll
	*/
	void NumberGameStateAskNewGame::Render()
	{
		std::cout << "Moechten Sie ein neues Spiel starten? [J]a oder [N]ein?" << std::endl;
		std::cout << "Auswahl: ";
	}

	/**
	* @brief Benutzereingabe
	*/
	void NumberGameStateAskNewGame::ProcessEvents()
	{
		std::cin >> mInputBuffer;
	}

	/**
	* @brief Ausführung der Logik
	* 
	* Es werden nur die Übergangsbedingungen geprüft
	*/
	void NumberGameStateAskNewGame::Update()
	{
		checkTransitions();
	}
}