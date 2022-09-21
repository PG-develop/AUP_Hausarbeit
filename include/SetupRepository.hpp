#pragma once

#include "../include/PersistenceListService.hpp"
#include "../include/Setup.hpp"

namespace AUP_HA
{
	/**
	* @brief Repository für Einstellungen
	*
	*/
	class SetupRepository
	{
	public:
		SetupRepository();
		~SetupRepository();

		void SetAmountOfChoices(std::int32_t value_p);
		void SetMaxRange(std::int32_t value_p);
		void SetSetup(Setup setup_p);
		void SetSetup(std::int32_t amountOfChoices_p, std::int32_t maxAmount_p);

		std::int32_t GetAmountOfChoices() const;
		std::int32_t GetMaxRange() const;

	private:
		std::unique_ptr<PersistenceListService<Setup>> mPersitenceSetupList; /**< PersistenceListService */
		Setup	mSetup;	/**< Setupdaten (Model) */
	};
}