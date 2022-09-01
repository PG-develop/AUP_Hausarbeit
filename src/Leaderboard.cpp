#include "../include/Leaderboard.hpp"
#include "../include/TXTUserPersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*/
	Leaderboard::Leaderboard()
	{
		mUserRepository = std::make_unique<UserRepository>();
	}

	/**
	* @brief Destruktor
	*/
	Leaderboard::~Leaderboard()
	{
	}

}