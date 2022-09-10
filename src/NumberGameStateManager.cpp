#include <cassert>
#include <memory>

#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	NumberGameStateManager::NumberGameStateManager(UserRepository& userRepository, Game& game) : mCheatCodes()
	{
		mUserRepository = &userRepository;
		mGame = &game;

		registerTransitions();
		registerCheatCodes();
	}

	NumberGameStateManager::~NumberGameStateManager()
	{
	}

	void NumberGameStateManager::registerEndGameHandler(std::function<void()> handler)
	{
		mEndGame = handler;
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

	UserRepository& NumberGameStateManager::getUserRepository()
	{
		return *mUserRepository;
	}

	void NumberGameStateManager::changeState(GameStates::ID stateID)
	{
		// Wenn der State "ENDE" besteht, beende das Spiel.
		if (stateID == GameStates::END)
		{
			mEndGame();
		}
		else
		{
			auto found = mFactory.find(stateID);
			assert(found != mFactory.end());

			// Nur wenn sich die stateID von der aktuelle Unterscheidet, wird ein neuer State instanziiert.
			if (mActiveID != stateID)
			{
				mActiveID = stateID;
				mActiveState = found->second();
			}
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
		mTransitionHandlers[GameStates::TRANSITION::EMPTY] = [&](const std::string& string) {
			return onEmpty(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::NN]	= [&](const std::string& string) {
			return onNoNumber(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::NH]	= [&](const std::string& string) {
			return onHitOrNoHit(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::OB]	= [&](const std::string& string) {
			return onOutBorders(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::L] = [&](const std::string& string) {
			return onToLeaderboard(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::I] = [&](const std::string& string) {
			return onToIfNewGame(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::NG] = [&](const std::string& string) {
			return onNewGame(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::C] = [&] (const std::string& string) {
			return onNegativ(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::W] = [&](const std::string& string) {
			return onWin(string);
		};
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
		
		// Nur wenn die Beschränkung der Versuche auf 0 gesetzt ist geht das Spiel ohne Einschränlung weiter.
		if (mGame->getMaxTries() == 0)
		{
			return GameStates::ID::STATE_2;
		}
		else
		{
			// Wenn die maximale Anzahl an Versuchen erreicht ist, beende das Spiel
			if (mGame->getMaxTries() == mGame->getTries())
			{
				return GameStates::ID::STATE_6;
			}

			// Ansonsten zum nächsten Versuch.
			else
			{
				return GameStates::ID::STATE_2;
			}
		}
	}

	// Funktion ist auf den CheatCode -456 angepasst
	std::optional<GameStates::ID> NumberGameStateManager::onWin(const std::string& string)
	{
		auto parsedString = Utilities::ParseStringToInt(string);

		if (parsedString)
		{
			if (*parsedString > 0)
			{
				return GameStates::STATE_6;
			}
		}
		return GameStates::STATE_9;
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
		if (string.compare("j") == 0)
		{
			return GameStates::FIRST;
		}
		
		if (string.compare("n") == 0)
		{
			return GameStates::END;
		}
		return std::nullopt;
	}
	std::optional<GameStates::ID> NumberGameStateManager::onNegativ(const std::string& string)
	{
		auto parsedString = Utilities::ParseStringToInt(string);

		if (*parsedString < 0)
		{
			// Prüfe, ob es einen Cheatcode gibt
			auto founded = mCheatCodes.find(*parsedString);
			if (founded != mCheatCodes.end())
			{
				return founded->second;
			}

			// Wenn es keinen speziellen Cheatcode gibt, beende das Spiel
			return GameStates::STATE_6;
		}

		return std::nullopt;
	}
	void NumberGameStateManager::registerCheatCodes()
	{
		mCheatCodes[-123] = GameStates::STATE_8;
		mCheatCodes[-456] = GameStates::STATE_9;
	}
}