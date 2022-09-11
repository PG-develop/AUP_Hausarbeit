#pragma once

namespace AUP_HA
{
	namespace States
	{
		enum ID
		{
			NONE,			/**< Kein aktiver State */
			INTRO,			/**< IntroState */
			MAIN,			/**< MainState */
			GAME,			/**< GameState */
			LEADERBOARD,	/**< LeaderboardState */
			SETUP,			/**< SetupState */
			GAMESETUP_GAME	/**< SetupGameState */
		};
	}

	namespace GameStates
	{
		//TODO: Namen der IDs müssen noch angepasst werden
		enum ID
		{
			NONE,
			FIRST,
			STATE_2,
			STATE_3,
			STATE_4,
			STATE_5,
			STATE_6,
			STATE_7,
			STATE_8,	// Negative Zahl ohne Sonderfunktion
			STATE_9,	// CheatState -123
			STATE_10,	// CheatState -456
			END
		};

		enum TRANSITION
		{
			EMPTY,
			N_EMPTY,
			NH,
			NN,
			OB,
			L,
			I,			// 
			NG,			// Neues Spiel
			E,			// Exit
			C,			// Sonderfunktionen
			W
		};
	}
}