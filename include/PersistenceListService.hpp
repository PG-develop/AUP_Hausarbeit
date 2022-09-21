#pragma once

#include <vector>

namespace AUP_HA
{
	/**
	* @class PersistenceListService
	* 
	* Abstrakte Klasse\n
	* Basisklasse für die PersistenceListServices
	* 
	* @tparam [T] Model für den Service
	*/
	template <typename T>
	class PersistenceListService
	{
	public:
		PersistenceListService();
		virtual ~PersistenceListService();

		virtual void			PushList(const std::vector<T>& list_p) = 0;
		virtual std::vector<T>& GetList() = 0;
		virtual void			Clear() = 0;

	protected:
		std::vector<T>			mList;	/**< Listenhalter */
	};

	/**
	* @brief Konstruktor
	* 
	* Keine Funktion
	*/
	template<typename T>
	inline PersistenceListService<T>::PersistenceListService()
	{
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	template<typename T>
	inline PersistenceListService<T>::~PersistenceListService()
	{
	}

}