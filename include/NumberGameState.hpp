#pragma once

#include <memory>

#include "../include/StatesIdentifier.hpp"
#include "../include/GameTransition.hpp"

namespace AUP_HA
{
	class NumberGameStateManager;

	class NumberGameState
	{
	public:
		typedef std::unique_ptr<NumberGameState> Ptr;

	public:
		NumberGameState(NumberGameStateManager& manager);
		virtual ~NumberGameState();

		virtual void render() = 0;
		virtual void processEvents() = 0;
		virtual void update() = 0;

	protected:
		void requestChange(GameStates::ID stateID);

		std::map<GameStates::TRANSITION, GameTransition::Ptr> mTransitionFacotry;

	private:
		NumberGameStateManager* mManager;
	};
}