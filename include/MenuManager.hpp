#pragma once

#include <cassert>
#include <functional>
#include <map>

namespace AUP_HA
{
	/**
	* @class MenuManager
	* @brief Menü-Manager für Listenauswahl
	* 
	* Manager für numerische Menüstrukturen\n
	* Für den generischen Typen T muss der verwendete Menu-Identifiziertyp angegeben werden.
	* 
	* @tparam [T] Menu-Identifiziierer aus der Datei MenuIdentifier.hpp
	*/
	template<typename T>
	class MenuManager
	{
	public:
		MenuManager();
		~MenuManager();

		void RegisterMenu(T menuID_p, std::function<void()> handler_p);
		void SelectMenuItem(T menuID_p);
		void SelectMenuItem(std::int32_t menuIntID_p);

		std::int32_t Count() const;

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
	* @brief Registriert EventHandler für das Menü.
	* 
	* Die Handler müssen in der gleichen Reihenfolge wie die zugehörigen
	* Aufrufzahlen registriert werden.
	* 
	* @param [menuID_p] T Identifikator für den FunktionsHandler
	* @param [handler_p] std::function<void()> Zu registrierender Handler
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline void MenuManager<T>::RegisterMenu(T menuID_p, std::function<void()> handler_p)
	{
		// Nur im DEBUG-Build prüfe, ob Identifikator bereits registriert wurde.
#ifdef _DEBUG
		auto found = mRegisteredHandlers.find(menuID_p);

		// Prüfe, ob die ID bereits vergeben wurde (nur DEBUG)
		assert(found == mRegisteredHandlers.end());
#endif

		// Füge den Handler dem Handlerregister hinzu
		mRegisteredHandlers[menuID_p] = handler_p;
	}

	/**
	* @brief Ruft den Handler von dem registriertem Identifikator auf
	* 
	* @param [menuID_p] T Identifikator
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline void MenuManager<T>::SelectMenuItem(T menuID_p)
	{
		// Prüfe, ob die ID vorhanden ist
		auto found = mRegisteredHandlers.find(menuID_p);

		// Wenn kein Identifiziierer gefunden wurde, gebe Programmfehler aus (nur DEBUG)
		assert(found != mRegisteredHandlers.end());

		// Handleraufruf
		found->second();
	}

	/**
	* @brief Ruft den Handler von dem registriertem Identifikator auf.
	* Es erfolgt keine Prüfung, ob der Identifikator auch tatsächlich existiert
	* 
	* @param [menuIntID_p] std::int32_t Identifikator als Int
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline void MenuManager<T>::SelectMenuItem(std::int32_t menuIntID_p)
	{
		// Cast int zu Identifiziierer EnumID und rufe Funktion void MenuManager<T>::selectMenuItem(T menuID) auf
		SelectMenuItem(static_cast<T>(menuIntID_p));
	}

	/**
	* @brief Gibt die Anzahl der registrierten Handlers zurück.
	* 
	* @tparam [T] siehe Klassenbeschreibung
	*/
	template<typename T>
	inline std::int32_t MenuManager<T>::Count() const
	{
		return mRegisteredHandlers.size();
	}
}
