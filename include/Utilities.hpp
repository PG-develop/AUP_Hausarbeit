#pragma once

#include <iostream>
#include <optional>
#include <utility>

namespace AUP_HA
{
	/**
	* @class Utilities
	* @brief Allgemeine Funktionen
	*/
	class Utilities
	{
	public:
		static void ClearInputStream() noexcept;
		static std::optional<int> ParseStringToInt(const std::string& string) noexcept;
		static std::optional<int> ParseStringToIntWithLimits(const std::string& string, std::pair<int, int> limits) noexcept;
	};
}