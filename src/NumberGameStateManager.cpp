#include <cassert>
#include <memory>

#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateManager::NumberGameStateManager(UserRepository& userRepository, Game& game)
	{
		mUserRepository = &userRepository;
		mGame = &game;

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

	Game& NumberGameStateManager::getGame()
	{
		return *mGame;
	}

	void NumberGameStateManager::changeState(GameStates::ID stateID)
	{
		auto found = mFactory.find(stateID);
#ifdef _DEBUG
		assert(found != mFactory.end());
#endif
		// Nur wenn sich die stateID von der aktuelle Unterscheidet, wird ein neuer State instanziiert.
		if (mActiveID != stateID)
		{
			mActiveID = stateID;
			mActiveState = found->second();
		}
	}

	NumberGameStateManager::TransitionHandler& NumberGameStateManager::getTransition(GameStates::TRANSITION transitionID)
	{
		auto found = mTransitionHandlers.find(transitionID);

		assert(found != mTransitionHandlers.end());

		return found->second;
	}

	void NumberGameStateManager::registerTransitions()
	{
		mTransitionHandlers[GameStates::TRANSITION::EMPTY]	= std::bind(&NumberGameStateManager::onEmpty, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::NN]		= std::bind(&NumberGameStateManager::onNoNumber, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::NH]		= std::bind(&NumberGameStateManager::onHitOrNoHit, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::OB]		= std::bind(&NumberGameStateManager::onOutBorders, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::L]		= std::bind(&NumberGameStateManager::onToLeaderboard, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::I]		= std::bind(&NumberGameStateManager::onToIfNewGame, this, std::placeholders::_1);
		mTransitionHandlers[GameStates::TRANSITION::NG]		= std::bind(&NumberGameStateManager::onNewGame, this, std::placeholders::_1);
	}

	std::optional<GameStates::ID> NumberGameStateManager::onEmpty(const std::string& string)
	{
		if (string.empty())
		{
			return GameStates::ID::FIRST;
		}
		else
		{
			User user(string);

			mGame->newGame(user);
			return GameStates::ID::STATE_2;
		}
	}

	std::optional<GameStates::ID> NumberGameStateManager::onNoNumber(const std::string& string)
	{
		auto parsedString = Utilities::ParseStringToInt(string);

		// Wenn String nicht valide ist, dann gehe über in State 3 (NoNumber)
		if (!parsedString)
		{
			return GameStates::ID::STATE_3;
		}
		return std::nullopt;
	}

	std::optional<GameStates::ID> NumberGameStateManager::onHitOrNoHit(const std::string& string)
	{
		// an der Stelle, muss der String definitiv eine Zahl sein.
		auto parsedString = Utilities::ParseStringToInt(string);

		// String war keine Zahl, wenn hier gestoppt [[DEBUG]]
		assert(parsedString);

		// Wurde die Zahl gefunden?
		if (mGame->check(*parsedString))
		{
			return GameStates::ID::STATE_5;
		}
		return GameStates::ID::STATE_2;
	}

	std::optional<GameStates::ID> NumberGameStateManager::onOutBorders(const std::string& string)
	{
		auto limits = std::make_pair<const std::int32_t&, const std::int32_t&>(mGame->getMinBorder(), mGame->getMaxBorder());
		auto parsedString = Utilities::ParseStringToIntWithLimits(string, limits);

		if (!parsedString)
		{
			return GameStates::ID::STATE_4;
		}
		return std::nullopt;
	}
	std::optional<GameStates::ID> NumberGameStateManager::onToLeaderboard(const std::string& string)
	{
		return GameStates::STATE_6;
	}
	std::optional<GameStates::ID> NumberGameStateManager::onToIfNewGame(const std::string& string)
	{
		return GameStates::STATE_7;
	}
	std::optional<GameStates::ID> NumberGameStateManager::onNewGame(const std::string& string)
	{
		if (string.compare("y") == 0)
		{
			return GameStates::FIRST;
		}
		
		if (string.compare("n") == 0)
		{
			return GameStates::END;
		}
	}
}