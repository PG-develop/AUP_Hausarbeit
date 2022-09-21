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
	* Es wird eine Zahl generiert die ein Benutzer herausfinden muss.\n
	* Um die Option mit begrenzter Anzahl an Versuchen zu aktiveren, mMaxTries mit einer anderen Zahl als 0 initialisieren.
	*/
	class Game
	{
	public:
	public:

		Game();
		~Game();

		bool Check(const std::int32_t& number_p);

		const std::int32_t& GetMinBorder() const;
		const std::int32_t& GetMaxBorder() const;
		const std::int32_t& GetSearchedNumber() const;
		const std::int32_t& GetTries() const;
		const std::uint32_t& GetMaxTries() const;
		const User GetUser() const;

		void SetNewInput(const std::string& input_p);
		void SetNewTime(std::time_t time_p);
		const std::string& GetLastInput() const;

		void NewGame(User& user_p);

	private:
		void generateNewSearchedNumber();

	private:
		std::unique_ptr<SetupRepository>	mSetupRepository; /**< UserRepository */
		std::unique_ptr<User>				mUser;			  /**< Usermodel*/

		std::int32_t mMinBoarder;		/**< Untere Grenze */
		std::int32_t mMaxBoarder;		/**< Obere Grenze */
		std::int32_t mSearchedNumber;	/**< Gesuchte Zufallszahl */
		std::int32_t mTries;			/**< Anzahl von Versuchen */
		std::uint32_t mMaxTries;		/**< Maximale Anzahl von Versuchen (0 = unendlich)*/

		std::string mLastInput;			/**< Letzte Benutzereingabe */
	};
}