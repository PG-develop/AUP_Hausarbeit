#pragma once

#include "../include/PersistenceListService.hpp"
#include "../include/Setup.hpp"

namespace AUP_HA
{
	class SetupRepository
	{
	public:
		SetupRepository();
		~SetupRepository();

		void setAmountOfChoices(std::int32_t p_value);
		void setMaxRange(std::int32_t p_value);
		void setSetup(Setup p_setup);
		void setSetup(std::int32_t p_amountOfChoices, std::int32_t p_maxAmount);

		std::int32_t getAmountOfChoices() const;
		std::int32_t getMaxRange() const;

	private:
		std::unique_ptr<PersistenceListService<Setup>> mPersitenceSetupList;
		Setup	mSetup;
	};
}