#pragma once

#include <cassert>
#include <functional>
#include <map>

namespace AUP_HA
{
	/**
	* @class MenuManager
	* 
	* Manager f�r numerische Men�strukturen\n
	* F�r den generischen Typen T muss der verwendete Menu-Identifiziertyp angegeben werden.
	* 
	* @tparam [T] Menu-Identifiziierer aus der Datei MenuIdentifier.hpp
	*/
	template<typename T>
	class MenuManager
	{
	public:
		MenuManager();
		~MenuManager();

		void registerMenu(T menuID, std::function<void()> handler);
		void selectMenuItem(T menuID);
		void selectMenuItem(std::int32_t menuIntID);

		int count() const;

	private:
		std::map<T, std::function<void()>>	mRegisteredHandlers; /**< Funktionshandlerregister */

	};

	/**
	* @brief Konstruktor
	* 
	* Keine Funktion
	* 
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline MenuManager<T>::MenuManager()
	{
	}

	/**
	* @brief Destruktor
	*
	* Keine Funktion
	*
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline MenuManager<T>::~MenuManager()
	{
	}

	/**
	* @brief Registriert EventHandler f�r das Men�.
	* 
	* Die Handler m�ssen in der gleichen Reihenfolge wie die zugeh�rigen
	* Aufrufzahlen registriert werden.
	* 
	* @param [menuID] T Identifizierer f�r den FunktionsHandler
	* @param [handler] std::function<void()> Zu registrierender Handler
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline void MenuManager<T>::registerMenu(T menuID, std::function<void()> handler)
	{
		// Nur im DEBUG-Build pr�fe, ob Identifizierer bereits registriert wurde.
#ifdef _DEBUG
		auto found = mRegisteredHandlers.find(menuID);

		// Pr�fe, ob die ID bereits vergeben wurde (nur DEBUG)
		assert(found == mRegisteredHandlers.end());
#endif

		// F�ge den Handler dem Handlerregister hinzu
		mRegisteredHandlers[menuID] = handler;
	}

	/**
	* @brief Ruft den Handler von dem registriertem Identifizierer auf
	* 
	* @param [menuID] T Identifizierer
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline void MenuManager<T>::selectMenuItem(T menuID)
	{
		// Pr�fe, ob die ID vorhanden ist
		auto found = mRegisteredHandlers.find(menuID);

		// Wenn kein Identifiziierer gefunden wurde, gebe Programmfehler aus (nur DEBUG)
		assert(found != mRegisteredHandlers.end());

		// Handleraufruf
		found->second();
	}

	/**
	* @brief Ruft den Handler von dem registriertem Identifizierer auf.
	* Es erfolgt keine Pr�fung, ob der Identifizierer auch tats�chlich existiert
	* 
	* @param [menuID] std::int32_t Identifizierer als Int
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline void MenuManager<T>::selectMenuItem(std::int32_t menuIntID)
	{
		// Cast int zu Identifiziierer EnumID und rufe Funktion void MenuManager<T>::selectMenuItem(T menuID) auf
		selectMenuItem(static_cast<T>(menuIntID));
	}

	/**
	* @brief Gibt die Anzahl der registrierten Handlers zur�ck.
	* 
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline int MenuManager<T>::count() const
	{
		return mRegisteredHandlers.size();
	}
}
