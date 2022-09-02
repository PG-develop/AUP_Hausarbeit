#include "../include/NumberGameState.hpp"
#include "../include/NumberGameStateManager.hpp"

namespace AUP_HA
{
	NumberGameState::NumberGameState(NumberGameStateManager& manager) : mInputBuffer(), mManager{&manager}
	{
	}
	NumberGameState::~NumberGameState()
	{
	}
	void NumberGameState::requestChange(GameStates::ID stateID)
	{
		mManager->changeState(stateID);
	}
	void NumberGameState::checkTransitions()
	{
		for (const auto& item : mTransitionList)
		{
			auto result = item(mInputBuffer);

			if (result)
			{
				requestChange(*result);
				break;
			}
		}
	}
}