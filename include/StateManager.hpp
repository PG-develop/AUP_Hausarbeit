#pragma once
/*
* @Title StateManager
*
* @Description Steuerung der Prgrammzustände
*/

#include <functional>
#include <map>
#include <cassert>

#include "StatesIdentifier.hpp"
#include "State.hpp"

namespace AUP_HA 
{
	class StateManager 
	{
	public:
		explicit StateManager();
		~StateManager();

		template<typename T>
		void registerStates(States::ID stateID);

		void render();
		void processEvents();
		void update();


		void changeState(States::ID stateID);
		bool hasActiveState() const;

	private:
		State::Ptr											mActiveState;
		std::map<States::ID, std::function<State::Ptr()>>	mStateFactories;
	};

	template<typename T>
	inline void StateManager::registerStates(States::ID stateID)
	{
		mStateFactories[stateID] =
			[this]()
		{
			return State::Ptr(new T(*this));
		};
	}
}