#include "../include/NumberGameStateAskNewGame.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	NumberGameStateAskNewGame::NumberGameStateAskNewGame(NumberGameStateManager& manager) : NumberGameState(manager)
	{
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::NG));
		mTransitionList.push_back(manager.getTransition(GameStates::TRANSITION::I));
	}
	NumberGameStateAskNewGame::~NumberGameStateAskNewGame()
	{
	}
	void NumberGameStateAskNewGame::render()
	{
		std::cout << "Moechten Sie ein neues Spiel starten? [J]a oder [N]ein?" << std::endl;
		std::cout << "Auswahl: ";
	}
	void NumberGameStateAskNewGame::processEvents()
	{
		std::cin >> mInputBuffer;
	}
	void NumberGameStateAskNewGame::update()
	{
		checkTransitions();
	}
}