#pragma once

#include "../include/Setup.hpp"
#include "../include/PersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @class TXTUserPersistenceListService
	* 
	* Service für das Model Setup\n
	* Daten werden in einer TXT-Datei gespeichert.
	*/
	class TXTSetupPersistenceListService : public PersistenceListService<Setup>
	{
	public:
		TXTSetupPersistenceListService();
		virtual ~TXTSetupPersistenceListService();

		virtual void				PushList(const std::vector<Setup>& list_p);
		virtual std::vector<Setup>& GetList();
		virtual void				Clear();

	private:
		std::string mFileName;	/**< Name der zu speichernden Datei */
	};
}