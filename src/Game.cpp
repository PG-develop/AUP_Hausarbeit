#include <chrono>
#include <random>

#include "../include/Game.hpp"
#include "../include/SetupRepository.hpp"

namespace AUP_HA
{
	Game::Game()
		: mMinBoarder{ }
		, mMaxBoarder{ }
		, mSearchedNumber{ }
		, mTries{ }
		, mMaxTries{ }
	{
		mSetupRepository = std::make_unique<SetupRepository>();
	}

	Game::~Game()
	{
	}

	/**
	* @brief �berpr�fe Zahleneingabe
	* 
	* @param number zu pr�fende Zahl
	* @return true, wenn die Zahl gefunden wurde, andernfalls false
	*/
	bool Game::check(const std::int32_t& number)
	{
		// Erh�he die Versuchsanzahl um eins
		mTries++;

		// Pr�fe, ob die gesuchte Zahl gefunden wurde
		if (number == mSearchedNumber)
		{
			mUser->Tries = mTries;
			mUser->Date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			return true;
		}
		else
		{
			// Wenn die gepr�fte Zahl nicht gefunden wurde, setze die Grenzen neu auf die angegebene Zahl:
			// wenn die Zahl kleiner als die gesuchte Zahl ist, dann wird die untere Grenze neu gesetzt,
			if (number < mSearchedNumber)
			{
				mMinBoarder = number;
			}
			// wenn die Zahl gr��er als die geesuchte Zahl ist, dann wird die obere Grenze neu gesetzt.
			else
			{
				mMaxBoarder = number;
			}
			return false;
		}
	}

	const std::int32_t& Game::getMinBorder() const
	{
		return mMinBoarder;
	}

	const std::int32_t& Game::getMaxBorder() const
	{
		return mMaxBoarder;
	}

	const std::int32_t& Game::getSearchedNumber() const
	{
		return mSearchedNumber;
	}

	const std::int32_t& Game::getTries() const
	{
		return mTries;
	}

	const std::uint32_t& Game::getMaxTries() const
	{
		return mMaxTries;
	}

	const User Game::getUser() const
	{
		return *mUser;
	}

	void Game::setNewInput(const std::string& input)
	{
		mLastInput = input;
	}

	void Game::setNewTime(std::time_t time)
	{
		mUser->Date = time;
	}

	const std::string& Game::getLastInput() const
	{
		return mLastInput;
	}

	/**
	* @brief Initialisiert ein neues Spiel
	*/
	void Game::newGame(User& user)
	{
		mUser = std::make_unique<User>(user);

		// TODO: Daten aus einer Configdatei einlesen
		mTries = 0;
		mMaxTries = mSetupRepository->getAmountOfChoices();
		mMinBoarder = 1;
		mMaxBoarder = mSetupRepository->getMaxRange();
		generateNewSearchedNumber();
	}

	/**
	* @brief Generiert eine neue zuf�llige gesuchte Zahl innerhalb der gesetzten Grenzen
	*/
	void Game::generateNewSearchedNumber()
	{
		// Zufallszahl generieren
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<std::int32_t> distr(mMinBoarder, mMaxBoarder);

		mSearchedNumber = distr(eng);
	}

}