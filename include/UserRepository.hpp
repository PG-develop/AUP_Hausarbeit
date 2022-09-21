#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "../include/User.hpp"
#include "../include/PersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @brief Repository für Userdaten 
	* 
	*/
	class UserRepository
	{
	public:
		UserRepository();
		~UserRepository();

		const std::vector<User>& GetUserSortedByRang();
		void SaveOrUpdate(User user_p);
		void ClearRepository();

	private:
		std::unique_ptr<PersistenceListService<User>> mPersistenceUserList; /**< PersistenceListService */
		std::vector<User> mUserList;	/**< Benutzerliste */
	};
}