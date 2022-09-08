#pragma once

#include "../include/Setup.hpp"
#include "../include/PersistenceListService.hpp"

namespace AUP_HA
{
	class TXTSetupPersistenceListService : public PersistenceListService<Setup>
	{
	public:
		TXTSetupPersistenceListService();
		virtual ~TXTSetupPersistenceListService();

		virtual void				pushList(const std::vector<Setup>& list);
		virtual std::vector<Setup>& getList();
		virtual void				clear();

	private:
		std::string mFileName;
	};
}