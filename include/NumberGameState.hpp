#pragma once

#include <memory>
#include <string>
#include <optional>
#include <vector>
#include <functional>

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
		void checkTransitions();

		//std::map<GameStates::TRANSITION, GameTransition::Ptr> mTransitionFacotry;

	protected:
		std::string mInputBuffer;

		// In dem Vector werden Funktionen gespeichert, in denen die Transitionbedingungen geprüft werden.
		std::vector<std::function<std::optional<GameStates::ID>(const std::string&)>> mTransitionList;

	private:
		NumberGameStateManager* mManager;
	};
}