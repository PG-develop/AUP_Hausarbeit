#include <chrono>
#include <random>

#include "../include/Game.hpp"
#include "../include/SetupRepository.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Parameter werden initialisiert
	*/
	Game::Game()
		: mMinBoarder{ }
		, mMaxBoarder{ }
		, mSearchedNumber{ }
		, mTries{ }
		, mMaxTries{ }
	{
		mSetupRepository = std::make_unique<SetupRepository>();
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	Game::~Game()
	{
	}

	/**
	* @brief Zahleneingabepr�fung
	* 
	* @param [number_p] std::int32_t zu pr�fende Zahl
	* @return true, wenn die Zahl gefunden wurde, andernfalls false
	*/
	bool Game::Check(const std::int32_t& number_p)
	{
		// Erh�he die Versuchsanzahl um eins
		mTries++;

		// Pr�fe, ob die gesuchte Zahl gefunden wurde
		if (number_p == mSearchedNumber)
		{
			// Usermodel mit Daten f�r das Spiel f�llen
			mUser->Tries = mTries;
			mUser->Date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			return true;
		}

		// gesuchte Zahl wurde nicht gefunden
		else
		{
			// Wenn die gepr�fte Zahl nicht gefunden wurde, setze die Grenzen neu auf die angegebene Zahl:
			// wenn die Zahl kleiner als die gesuchte Zahl ist, dann wird die untere Grenze neu gesetzt,
			if (number_p < mSearchedNumber)
			{
				mMinBoarder = number_p;
			}
			// wenn die Zahl gr��er als die geesuchte Zahl ist, dann wird die obere Grenze neu gesetzt.
			else
			{
				mMaxBoarder = number_p;
			}
			return false;
		}
	}

	/**
	* @brief Gibt die aktuelle untere Grenze zur�ck
	* 
	* @return std::int32_t untere Grenze
	*/
	const std::int32_t& Game::GetMinBorder() const
	{
		return mMinBoarder;
	}

	/**
	* @brief Gibt die aktuelle obere Grenze zur�ck
	*
	* @return std::int32_t obere Grenze
	*/
	const std::int32_t& Game::GetMaxBorder() const
	{
		return mMaxBoarder;
	}

	/**
	* @brief Gibt die aktuelle gesuchte Nummer zur�ck
	*
	* @return std::int32_t gesuchte Nummer
	*/
	const std::int32_t& Game::GetSearchedNumber() const
	{
		return mSearchedNumber;
	}

	/**
	* @brief Gibt die Anzahl von bereits durchgef�hrten Versuchen zur�ck
	*
	* @return std::int32_t Anzahl von Versuchen
	*/
	const std::int32_t& Game::GetTries() const
	{
		return mTries;
	}

	/**
	* @brief Gibt die maximale Anzahl von Versuchen zur�ck
	* 
	* Wenn die Grenze �berschritten wird, wird das Spiel beendet
	*
	* @return std::int32_t Maximale Anzahl an Versuchen
	*/
	const std::uint32_t& Game::GetMaxTries() const
	{
		return mMaxTries;
	}

	/**
	* @brief Gibt eine Referenz auf das aktuelle Usermodel zur�ck
	* 
	* @return User Usermodel
	*/
	const User Game::GetUser() const
	{
		return *mUser;
	}

	/**
	* @brief �bernimmt eine neue Benutzereingabe
	* 
	* @param [input_p] std::string Benutzereingabe
	*/
	void Game::SetNewInput(const std::string& input_p)
	{
		mLastInput = input_p;
	}

	/**
	* @brief Zeit�bergabe an das Usermodel
	* 
	* @param [time_p] std::time_t Zeitstempel
	*/
	void Game::SetNewTime(std::time_t time_p)
	{
		mUser->Date = time_p;
	}

	/**
	* @brief Gibt letzte Benutzereingabe zur�ck
	* 
	* @return std::string letzte Benutzereingabe
	*/
	const std::string& Game::GetLastInput() const
	{
		return mLastInput;
	}

	/**
	* @brief Initialisiert ein neues Spiel
	* 
	* @param [user_p] User Usermodel
	*/
	void Game::NewGame(User& user_p)
	{
		// Erstelle ein neues Usermodel
		mUser = std::make_unique<User>(user_p);

		// Lade Initialisierungsdaten f�r das neue Spiel
		mTries = 0;
		mMaxTries = mSetupRepository->GetAmountOfChoices();
		mMinBoarder = 1;
		mMaxBoarder = mSetupRepository->GetMaxRange();

		// Erstelle neue Zufallszahl
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