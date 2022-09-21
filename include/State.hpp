#pragma once

#include <memory>

#include "StatesIdentifier.hpp"

namespace AUP_HA
{
	// Vorwärtsdeklaration
	class StateManager;

	/**
	* @class Virtuelle Basisklasse für alle States
	*/
	class State 
	{
	public:
		typedef std::unique_ptr<State> Ptr;

	public:
		State(StateManager& stateManager_p);
		virtual ~State();

		virtual void Render() = 0;
		virtual void ProcessEvents() = 0;
		virtual void Update() = 0;

	protected:
		void requestChange(States::ID stateID_p);

	private:
		StateManager* mStateManager;	/**< Pointer auf seinen StateManager */
	};
}