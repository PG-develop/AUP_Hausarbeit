#pragma once

#include <iostream>

#include "../include/User.hpp"

namespace AUP_HA
{
	// Vorwärts Deklaration
	class SetupRepository;

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

		const std::int32_t& getMinBorder() const;
		const std::int32_t& getMaxBorder() const;
		const std::int32_t& getSearchedNumber() const;
		const std::int32_t& getTries() const;
		const std::uint32_t& getMaxTries() const;
		const User getUser() const;

		void setNewInput(const std::string& input);
		void setNewTime(std::time_t time);
		const std::string& getLastInput() const;

		void newGame(User& user);

	private:
		void generateNewSearchedNumber();

	private:
		std::unique_ptr<SetupRepository>	mSetupRepository;
		std::unique_ptr<User>				mUser;

		std::int32_t mMinBoarder;
		std::int32_t mMaxBoarder;
		std::int32_t mSearchedNumber;
		std::int32_t mTries;
		std::uint32_t mMaxTries;

		std::string mLastInput;
	};
}