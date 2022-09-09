#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "../include/User.hpp"
#include "../include/PersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @class UserRepository
	* 
	* 
	*/
	class UserRepository
	{
	public:
		UserRepository();
		~UserRepository();

		const std::vector<User>& GetUserSortedByRang();
		void SaveOrUpdate(User user);
		void ClearRepository();

	private:
		std::unique_ptr<PersistenceListService<User>> mPersistenceUserList;
		std::vector<User> mUserList;
	};
}