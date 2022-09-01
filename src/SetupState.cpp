#include "../include/SetupState.hpp"

namespace AUP_HA
{
	SetupState::SetupState(StateManager& stateManager) : State(stateManager)
	{
	}

	SetupState::~SetupState()
	{
	}

	void SetupState::render()
	{
		std::cout << "SetupState" << std::endl;
	}

	void SetupState::processEvents()
	{
	}

	void SetupState::update()
	{
	}
}