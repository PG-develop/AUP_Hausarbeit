#pragma once

#include <vector>

namespace AUP_HA
{
	template <typename T>
	class PersistenceListService
	{
	public:
		PersistenceListService();
		virtual ~PersistenceListService();

		virtual void			pushList(const std::vector<T>& list) = 0;
		virtual std::vector<T>& getList() = 0;
		virtual void			clear() = 0;
	};

	template<typename T>
	inline PersistenceListService<T>::PersistenceListService()
	{
	}

	template<typename T>
	inline PersistenceListService<T>::~PersistenceListService()
	{
	}

}