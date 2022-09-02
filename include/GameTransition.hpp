#pragma once

#include <memory>

#include "../include/NumberGameState.hpp"

namespace AUP_HA
{
	struct GameTransition
	{
	public:
		template <typename T>
		T Action();
		NumberGameState::Ptr operator()();
	};
	template<typename T>
	inline T GameTransition::Action()
	{
		return std::move(std::make_unique<T>());
	}

}