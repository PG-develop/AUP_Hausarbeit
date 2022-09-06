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
	{
		
	}

	Game::~Game()
	{
	}

	/**
	* @brief Überprüfe Zahleneingabe
	* 
	* @param number zu prüfende Zahl
	* @return true, wenn die Zahl gefunden wurde, andernfalls false
	*/
	bool Game::check(const std::int32_t& number)
	{
		// Erhöhe die Versuchsanzahl um eins
		mTries++;

		// Prüfe, ob die gesuchte Zahl gefunden wurde
		if (number == mSearchedNumber)
		{
			mUser->Tries = mTries;
			mUser->Date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			return true;
		}
		else
		{
			// Wenn die geprüfte Zahl nicht gefunden wurde, setze die Grenzen neu auf die angegebene Zahl:
			// wenn die Zahl kleiner als die gesuchte Zahl ist, dann wird die untere Grenze neu gesetzt,
			if (number < mSearchedNumber)
			{
				mMinBoarder = number;
			}
			// wenn die Zahl größer als die geesuchte Zahl ist, dann wird die obere Grenze neu gesetzt.
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

	const User& Game::getUser() const
	{
		return *mUser;
	}

	void Game::setNewInput(const std::string& input)
	{
		mLastInput = input;
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
		mMaxTries = 5;
		mMinBoarder = 1;
		mMaxBoarder = 1000;
		generateNewSearchedNumber();
	}

	/**
	* @brief Generiert eine neue zufällige gesuchte Zahl innerhalb der gesetzten Grenzen
	*/
	void Game::generateNewSearchedNumber()
	{
		//TODO: Zahlengenerator
		mSearchedNumber = 500;
	}

}