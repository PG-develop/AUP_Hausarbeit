#pragma once

namespace AUP_HA
{
	/**
	* @brief Namensraum für Grundgerüst-States
	*/
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

	/**
	* @brief Namensraum für Spiel-States
	*/
	namespace GameStates
	{
		enum ID
		{
			NONE,		/**< Kein aktiver State */
			STATE_1,	/**< NumberGameStateName: Name eingeben */
			STATE_2,	/**< NumberGameStateNormal: Normaler Spielablauf */
			STATE_3,	/**< NumberGameStateNoNumber: Keine Nummer */
			STATE_4,	/**< NumberGameStateOutBorders: Außerhalb der Grenzen */
			STATE_5,	/**< NumberGameStateWin: gesuchte Nummer gefunden */
			STATE_6,	/**< NumberGameStateShowLeaderboard: Bestenliste anzeigen */
			STATE_7,	/**< NumberGameStateAskNewGame: Frage nach neuem Spiel */
			STATE_8,	/**< NumberGameStateShowSearchedNummer: Gesuchte Nummer wird angezeigt */
			STATE_9,	/**< NumberGameStateCheatWin: Sofort gewonnen */
			END			/**< Spielende */
		};

		enum TRANSITION
		{
			EMPTY,		/**< Abfrage, ob String leer oder nicht leer ist */
			NH,			/**< Abfrage, ob gesuchte Nummer gefunden wurde */
			NN,			/**< Abfrage, ob String eine Nummer ist */
			OB,			/**< Abfrage, ob Nummer innerhalb der Grenzen liegt */
			L,			/**< Anzeige der Bestenliste */
			I,			/**< Anzeige, ob ein neues Spiel gespielt werden soll */
			NG,			/**< Abfrage, ob ein neues Spiel gespielt werden soll */
			E,			/**< Spiel beenden */
			C,			/**< Sonderfunktionen */
			W			/**< Direkt gewonnen */
		};
	}
}