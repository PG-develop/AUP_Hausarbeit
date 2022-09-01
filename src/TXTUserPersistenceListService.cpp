#include "TXTUserPersistenceListService.hpp"

namespace AUP_HA
{
	TXTUserPersistenceListService::TXTUserPersistenceListService() : PersistenceListService()
	{

	}

	TXTUserPersistenceListService::~TXTUserPersistenceListService()
	{
	}

	void TXTUserPersistenceListService::pushList(const std::vector<User>& list)
	{
	}

	std::vector<User>& TXTUserPersistenceListService::getList()
	{
		return *(new std::vector<User>());
	}

	void TXTUserPersistenceListService::clear()
	{
	}
}
