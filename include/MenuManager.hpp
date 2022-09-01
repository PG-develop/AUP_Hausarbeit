#pragma once

#include <cassert>
#include <functional>
#include <map>

namespace AUP_HA
{
	/**
	* @class MenuManager
	* @brief Manager f�r numerische Men�s.
	* 
	* F�r den generischen Typen T muss der verwendete Identifiziertyp angegeben werden.
	*/
	template<typename T>
	class MenuManager
	{
	public:
		MenuManager();
		~MenuManager();

		void registerMenu(T menuID, std::function<void()> handler);
		void selectMenuItem(T menuID);
		void selectMenuItem(int menuIntID);

		int count() const;

	private:
		std::map<T, std::function<void()>>	mRegisteredHandlers;

	};

	template<typename T>
	inline MenuManager<T>::MenuManager()
	{
	}

	template<typename T>
	inline MenuManager<T>::~MenuManager()
	{
	}

	/**
	* @brief Registriert EventHandler f�r das Men�.
	* 
	* @param menuID	Identifizierer f�r den Handler
	* @param handler Zu registrierender Handler
	*/
	template<typename T>
	inline void MenuManager<T>::registerMenu(T menuID, std::function<void()> handler)
	{
#ifdef _DEBUG
		auto found = mRegisteredHandlers.find(menuID);

		// Pr�fe, ob die ID bereits vergeben wurde
		if (found != mRegisteredHandlers.end()) 
		{
			assert("ID wurde bereits registriert!");
		}
#endif
		mRegisteredHandlers[menuID] = handler;
	}

	/**
	* @brief Ruft den Handler von dem registriertem Identifizierer auf
	* 
	* @param menuID Identifizierer
	*/
	template<typename T>
	inline void MenuManager<T>::selectMenuItem(T menuID)
	{
		auto found = mRegisteredHandlers.find(menuID);
#ifdef _DEBUG
		// Pr�fe, ob die ID vorhanden ist
		if (found == mRegisteredHandlers.end())
		{
			assert("Die ID wurde nicht gefunden. Gehen Sie sicher, dass die ID korrekt registriert wurde.");
		}
#endif
		// Handleraufruf
		found->second();
	}

	/**
	* @brief Ruft den Handler von dem registriertem Identifizierer auf.
	* Es erfolgt keine Pr�fung, ob der Identifizierer auch tats�chlich existiert
	* 
	* @param menuID Identifizierer als Int
	*/
	template<typename T>
	inline void MenuManager<T>::selectMenuItem(int menuIntID)
	{
		selectMenuItem(static_cast<T>(menuIntID));
	}

	/**
	* @brief Gibt die Anzahl der registrierten Handlers zur�ck.
	*/
	template<typename T>
	inline int MenuManager<T>::count() const
	{
		return mRegisteredHandlers.size();
	}
}
