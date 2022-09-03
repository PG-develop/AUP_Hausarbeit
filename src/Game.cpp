#include <chrono>

#include "../include/Game.hpp"

namespace AUP_HA
{
	Game::Game()
		: mMinBoarder{ }
		, mMaxBoarder{ }
		, mSearchedNumber{ }
		, mTries{ }
		, mMaxTries{ }
		, mUser{ }
	{
		
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
			mUser.Tries = mTries;
			mUser.Date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
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

	const std::int32_t& Game::getMinBoard() const
	{
		return mMinBoarder;
	}

	const std::int32_t& Game::getMaxBoarder() const
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

	/**
	* @brief Initialisiert ein neues Spiel
	*/
	void Game::newGame(User& user)
	{
		mUser = user;

		// TODO: Daten aus einer Configdatei einlesen
		mTries = 0;
		mMaxTries = 0;
		mMinBoarder = 1;
		mMaxBoarder = 1000;
		generateNewSearchedNumber();
	}

	/**
	* @brief Generiert eine neue zuf�llige gesuchte Zahl innerhalb der gesetzten Grenzen
	*/
	void Game::generateNewSearchedNumber()
	{
		//TODO: Zahlengenerator
		mSearchedNumber = 500;
	}

}