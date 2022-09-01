#pragma once

#include <memory>

#include "../include/UserRepository.hpp"

namespace AUP_HA
{
	class Leaderboard
	{
	public:
		Leaderboard();
		~Leaderboard();

	private:
		std::unique_ptr<UserRepository> mUserRepository;
	};
}


