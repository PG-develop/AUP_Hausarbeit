#pragma once

#include "../include/PersistenceListService.hpp"
#include "../include/User.hpp"

namespace AUP_HA
{
	class TXTUserPersistenceListService : public PersistenceListService<User>
	{
	public:
		TXTUserPersistenceListService();
		virtual ~TXTUserPersistenceListService();

		virtual void			   pushList(const std::vector<User>& list);
		virtual std::vector<User>& getList();
		virtual void			   clear();

	private:
		std::string mFileName;
	};

	

}