#pragma once

#include <iostream>

namespace AUP_HA
{
	/**
	* @brief Model User
	*
	* Speichert Daten f?r den Benutzer\n
	* Name des Benutzers\n
	* Spielzeitpunkt\n
	* ben?tigte Versuchsanzahl
	*/
	struct User
	{
		// Konstruktoren
		User() : User("default") { };	/**< Defaultkonstruktor */
		User(std::string name) :Name(name), Date(0), Tries(0) { }; /**< Zus?tzlicher Konstruktur mit Namen?bergabe */

		// Daten
		std::string  Name;	/**< Name des Benutzer */
		std::time_t  Date;	/**< Datum des Spiels */
		std::int32_t Tries;	/**< Anzahl der Versuche */
	};
}