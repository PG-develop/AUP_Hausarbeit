#pragma once

namespace AUP_HA
{
	namespace MainMenu
	{
		enum ID
		{
			GAME = 1,		/**< Wechsel zum GameState */
			SETUP,			/**< Wechsel zum SetupState */
			LEADERBOARD,	/**< Wechsel zum LeaderboardState */
			EXIT			/**< Programmende */
		};
	}

	namespace SetupMenu
	{
		enum ID
		{
			GAMESETUP = 1,
			CLEAR,
			EXIT,
			GAMESETUP_AMOUNT_OF_CHOICES,
			GAMESETUP_MAX_RANGE,
		};
	}

	namespace SETUP_GAMESETUP
	{
		enum ID
		{
			GAMESETUP_CHANGE_AMOUNT_OF_CHOICES = 1,
			GAMESETUP_CHANGE_MAX_RANGE,
			EXIT
		};
	}
}