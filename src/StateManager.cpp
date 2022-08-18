#include "StateManager.hpp"

namespace AUP_HA 
{
	/*
	*
	*/
	StateManager::StateManager() : mStateFactories()
	{
	}

	/*
	*
	*/
	StateManager::~StateManager()
	{
	}

	/*
	*
	*/
	void StateManager::render()
	{
		if (mActiveState)
		{
#ifndef _DEBUG
			system("cls");
#endif
			mActiveState->render();
		}
	}

	/*
	*
	*/
	void StateManager::processEvents()
	{
		if (mActiveState)
		{
			mActiveState->processEvents();
		}
	}

	/*
	*
	*/
	void StateManager::update()
	{
		if (mActiveState)
		{
			mActiveState->update();
		}
	}

	/*
	*
	*/
	void StateManager::changeState(States::ID stateID)
	{
		if (stateID == States::NONE)
		{
			mActiveState.reset();
		}
		else
		{
			auto found = mStateFactories.find(stateID);
			assert(found != mStateFactories.end());

			if (mActiveState) 
			{
				mActiveState.reset();
			}
			mActiveState = found->second();
		}
	}

	/*
	*
	*/
	bool StateManager::hasActiveState() const
	{
		return static_cast<bool>(mActiveState);
	}
}
