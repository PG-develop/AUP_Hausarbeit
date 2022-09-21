#pragma once

#include "../include/PersistenceListService.hpp"
#include "../include/User.hpp"

namespace AUP_HA
{
	/**
	* @class TXTUserPersistenceListService
	*
	* Service für das Model User\n
	* Daten werden in einer TXT-Datei gespeichert.
	*/
	class TXTUserPersistenceListService : public PersistenceListService<User>
	{
	public:
		TXTUserPersistenceListService();
		virtual ~TXTUserPersistenceListService();

		virtual void			   PushList(const std::vector<User>& list_p);
		virtual std::vector<User>& GetList();
		virtual void			   Clear();

	private:
		std::string mFileName;	/**< Name der zu speichernden Datei */
	};
}