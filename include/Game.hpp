#pragma once

#include <iostream>

#include "../include/User.hpp"

namespace AUP_HA
{
	/**
	* @class Game
	* @brief Zahlenratespiel
	* 
	* Es wird eine Zahl generiert die ein Benutzer herausfinden muss. 
	* 
	* Um die Option mit begrenzter Anzahl an Versuchen zu aktiveren, mMaxTries mit einer anderen Zahl als 0 initialisieren.
	*/
	class Game
	{
	public:
	public:

		Game();
		~Game();

		bool check(const std::int32_t& number);

		const std::int32_t& getMinBoard() const;
		const std::int32_t& getMaxBoarder() const;
		const std::int32_t& getSearchedNumber() const;
		const std::int32_t& getTries() const;
		const std::uint32_t& getMaxTries() const;

		void newGame(User& user);

	private:
		void generateNewSearchedNumber();

	private:
		std::int32_t mMinBoarder;
		std::int32_t mMaxBoarder;
		std::int32_t mSearchedNumber;
		std::int32_t mTries;
		std::uint32_t mMaxTries;
		User mUser;
	};
}