#pragma once

#include <memory>
#include <map>
#include <functional>

#include "../include/NumberGameState.hpp"
#include "../include/StatesIdentifier.hpp"

namespace AUP_HA
{
	class NumberGameStateManager
	{
	public:
		explicit NumberGameStateManager();
		~NumberGameStateManager();

		template <typename T>
		void registerStates(GameStates::ID stateID);
		
		void render();
		void processEvents();
		void update();

		void changeState(GameStates::ID stateID);

	private:
		std::unique_ptr<NumberGameState>	mActualState;
		std::map<GameStates::ID, std::function<NumberGameState::Ptr()>> mFactory;
	};

	template<typename T>
	inline void NumberGameStateManager::registerStates(GameStates::ID stateID)
	{
		mStateFactories[stateID] =
			[this]()
		{
			return State::Ptr(new T(*this));
		};
	}
}