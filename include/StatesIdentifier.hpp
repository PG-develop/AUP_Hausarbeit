#pragma once

namespace AUP_HA
{
	namespace States
	{
		enum ID
		{
			NONE,
			INTRO,
			MAIN,
			GAME,
			LEADERBOARD,
			SETUP,
			GAMESETUP_GAME,
			GAMESETUP_CLEAR
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
			I,
			NG,
			E
		};
	}
}