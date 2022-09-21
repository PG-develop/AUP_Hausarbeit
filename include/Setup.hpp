#pragma once

#include <iostream>

namespace AUP_HA
{
	/**
	* @brief Model Setup
	* 
	* Speichert Daten für die Spieleinstellungen\n
	* Anzahl der Versuche\n
	* Streuchreichweite
	*/
	struct Setup
	{
		// Konstruktoren
		Setup() 
			: Setup(0,0) {};
		Setup(std::int32_t p_AmmountOfChoices, std::int32_t p_MaxRange) 
			: AmmountOfChoices(p_AmmountOfChoices), MaxRange(p_MaxRange) {};

		std::int32_t AmmountOfChoices;	/**< Versuchsanzahl */
		std::int32_t MaxRange;			/**< Streureichweite */

		// Operatoren
		friend bool operator==(const Setup& lhs, const Setup& rhs) {
			return (lhs.AmmountOfChoices == rhs.AmmountOfChoices) && (lhs.MaxRange == rhs.MaxRange) ? true : false;
		}
		friend bool operator!=(const Setup& lhs, const Setup& rhs) {
			return (lhs.AmmountOfChoices == rhs.AmmountOfChoices) && (lhs.MaxRange == rhs.MaxRange) ? false : true;
		}
	};
}