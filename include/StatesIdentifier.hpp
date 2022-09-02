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
			SETUP
		};
	}

	namespace GameStates
	{
		//TODO: Namen der IDs müssen noch angepasst werden
		enum ID
		{
			FIRST,
			STATE_2,
			STATE_3,
			STATE_4,
			STATE_5,
		};

		enum TRANSITION
		{
			EMPTY,
			N_EMPTY,
			NH,
			NN,
			OB,
			H
		};
	}
}