#pragma once

#include <memory>

#include "StatesIdentifier.hpp"

namespace AUP_HA
{
	class StateManager;

	class State 
	{
	public:
		typedef std::unique_ptr<State> Ptr;

	public:
		State(StateManager& stateManager);
		virtual ~State();

		virtual void render() = 0;
		virtual void processEvents() = 0;
		virtual void update() = 0;

	protected:
		void requestChange(States::ID stateID);

	private:
		StateManager* mStateManager;
	};
}