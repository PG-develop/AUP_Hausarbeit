#include "../include/State.hpp"
#include "../include/StateManager.hpp"

namespace AUP_HA 
{
	State::State(StateManager& stateManager) : mStateManager(&stateManager)
	{
	}

	State::~State()
	{
	}

	void State::requestChange(States::ID stateID)
	{
		mStateManager->changeState(stateID);
	}
}