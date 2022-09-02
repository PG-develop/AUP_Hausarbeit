#pragma once

#include <memory>
#include <map>
#include <functional>
#include <optional>

#include "../include/NumberGameState.hpp"
#include "../include/StatesIdentifier.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{
	class NumberGameStateManager
	{
	public:
		typedef std::function<std::optional<GameStates::ID>(const std::string&)> TransitionHandler;

	public:
		explicit NumberGameStateManager(UserRepository& userRepository);
		~NumberGameStateManager();

		template <typename T>
		void registerStates(GameStates::ID stateID);
		
		void render();
		void processEvents();
		void update();

		void changeState(GameStates::ID stateID);
		TransitionHandler& getTransition(GameStates::TRANSITION transitionID);

	private:
		//TODO:: Funktionsobjekte erstellen
		void registerTransitions();
		std::optional<GameStates::ID> onEmpty(const std::string& string);
		std::optional<GameStates::ID> onNotEmpty(const std::string& string);
		std::optional<GameStates::ID> onNoNumber(const std::string& string);
		std::optional<GameStates::ID> onNoHit(const std::string& string);
		std::optional<GameStates::ID> onOutBorders(const std::string& string);
		std::optional<GameStates::ID> onHit(const std::string& string);

	private:
		NumberGameState::Ptr	mActiveState;
		std::map<GameStates::ID, std::function<NumberGameState::Ptr()>> mFactory;
		std::map<GameStates::TRANSITION, std::function<std::optional<GameStates::ID>(const std::string&)>> mTransitionHandlers;

		UserRepository* mUserRepository;
	};

	template<typename T>
	inline void NumberGameStateManager::registerStates(GameStates::ID stateID)
	{
		mFactory[stateID] =
			[this]()
		{
			return NumberGameState::Ptr(new T(*this));
		};
	}
}