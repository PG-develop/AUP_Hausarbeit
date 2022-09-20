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
		static std::optional<std::int32_t> ParseStringToInt(const std::string& string) noexcept;
		static std::optional<std::int32_t> ParseStringToIntWithLimits(
			const std::string& string, 
			std::pair<std::int32_t, 
			std::int32_t> limits
		) noexcept;
	};
}