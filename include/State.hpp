#pragma once

#include <memory>

#include "StatesIdentifier.hpp"

namespace AUP_HA
{
	// Vorw�rtsdeklaration
	class StateManager;

	/**
	* @class Virtuelle Basisklasse f�r alle States
	*/
	class State 
	{
	public:
		typedef std::unique_ptr<State> Ptr;

	public:
		State(StateManager& stateManager);
		virtual ~State();

		virtual void Render() = 0;
		virtual void ProcessEvents() = 0;
		virtual void Update() = 0;

	protected:
		void requestChange(States::ID stateID);

	private:
		StateManager* mStateManager;	/**< Pointer auf seinen StateManager */
	};
}