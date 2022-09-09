#pragma once

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{

	class UserRepository;

	class NumberGameStateCheatWin : public NumberGameState
	{
	public:
		NumberGameStateCheatWin(NumberGameStateManager& manager);
		virtual ~NumberGameStateCheatWin();

		virtual void render();
		virtual void processEvents();
		virtual void update();

	private:
		UserRepository* mUserRepository;
	};
}