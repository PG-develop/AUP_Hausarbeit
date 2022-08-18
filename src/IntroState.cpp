#include "IntroState.hpp"

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
		std::cout << "IntroState" << std::endl;
	}

	void IntroState::processEvents()
	{
	}

	void IntroState::update()
	{
	}
}