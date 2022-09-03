#pragma once

#include <iostream>

namespace AUP_HA
{
	struct User
	{
		std::string  Name;
		std::time_t  Date;
		std::int32_t Tries;
	};
}