#include <cassert>
#include <memory>

#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateManager::NumberGameStateManager(UserRepository& userRepository)
	{
		mUserRepository = &userRepository;

		registerTransitions();
	}

	NumberGameStateManager::~NumberGameStateManager()
	{
	}

	void NumberGameStateManager::render()
	{
		mActiveState->render();
	}

	void NumberGameStateManager::processEvents()
	{
		mActiveState->processEvents();
		Utilities::ClearInputStream();

	}

	void NumberGameStateManager::update()
	{
		mActiveState->update();
	}

	void NumberGameStateManager::changeState(GameStates::ID stateID)
	{
		auto found = mFactory.find(stateID);
#ifdef _DEBUG
		assert(found != mFactory.end());
#endif
		if (mActiveState)
		{
			mActiveState.reset();
		}
		mActiveState = found->second();
	}

	NumberGameStateManager::TransitionHandler& NumberGameStateManager::getTransition(GameStates::TRANSITION transitionID)
	{
		// TODO: hier return-Anweisung eingeben
	}

	void NumberGameStateManager::registerTransitions()
	{
		mTransitionHandlers[GameStates::TRANSITION::EMPTY]	 = std::bind(&NumberGameStateManager::onEmpty, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::N_EMPTY] = std::bind(&NumberGameStateManager::onNotEmpty, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::NN]		 = std::bind(&NumberGameStateManager::onNoNumber, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::NH]		 = std::bind(&NumberGameStateManager::onNoHit, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::OB]		 = std::bind(&NumberGameStateManager::onOutBorders, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::H]		 = std::bind(&NumberGameStateManager::onHit, this, std::placeholders::_1);
	}

	std::optional<GameStates::ID> NumberGameStateManager::onEmpty(const std::string& string)
	{
		if (string.empty())
		{
			return std::nullopt;
		}
		else
		{
			return GameStates::ID::FIRST;
		}
	}

	std::optional<GameStates::ID> NumberGameStateManager::onNotEmpty(const std::string& string)
	{
		if (!string.empty())
		{
			return std::nullopt;
		}
		else
		{
			return GameStates::ID::STATE_2;
		}
	}

	std::optional<GameStates::ID> NumberGameStateManager::onNoNumber(const std::string& string)
	{
		return std::optional<GameStates::ID>();
	}

	std::optional<GameStates::ID> NumberGameStateManager::onNoHit(const std::string& string)
	{
		return std::optional<GameStates::ID>();
	}

	std::optional<GameStates::ID> NumberGameStateManager::onOutBorders(const std::string& string)
	{
		return std::optional<GameStates::ID>();
	}

	std::optional<GameStates::ID> NumberGameStateManager::onHit(const std::string& string)
	{
		return std::optional<GameStates::ID>();
	}

}