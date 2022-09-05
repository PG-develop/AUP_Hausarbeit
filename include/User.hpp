#pragma once

#include <iostream>

namespace AUP_HA
{
	struct User
	{
		// Konstruktoren
		User() { };
		User(std::string name) :Name(name) { };

		// Daten
		std::string  Name;
		std::time_t  Date;
		std::int32_t Tries;
	};
}