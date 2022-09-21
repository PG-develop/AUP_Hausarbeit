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
			GAMESETUP = 1,					/**< Wechsel zu den Spieleinstellungen */
			CLEAR,							/**< Bestenliste resetten */
			EXIT							/**< Zurück zum Main-State*/
		};
	}

	namespace SETUP_GAMESETUP
	{
		enum ID
		{
			GAMESETUP_CHANGE_AMOUNT_OF_CHOICES = 1,	/**< Versuchsanzahl */
			GAMESETUP_CHANGE_MAX_RANGE,				/**< Streureichweite */
			EXIT									/**< Zurück zum Setup-State */
		};
	}
}