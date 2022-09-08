#include <vector>

#include "../include/SetupRepository.hpp"
#include "../include/TXTSetupPersistenceListService.hpp"

namespace AUP_HA
{
	SetupRepository::SetupRepository() : mSetup()
	{
		mPersitenceSetupList = std::make_unique<TXTSetupPersistenceListService>();
		
		// Setupdaten aus dem Persistentservice laden
		std::vector<Setup> tempList = mPersitenceSetupList->getList();

		// Prüfe, ob Setupdaten vorhanden sind
		if (tempList.size() == 1)
		{
			mSetup = tempList[0];
		}

		// Wenn keine Daten existieren, initialisiere mit Werksdaten
		else
		{
			mSetup.AmmountOfChoices = 0;
			mSetup.MaxRange = 1000;

			tempList.push_back(mSetup);
			mPersitenceSetupList->pushList(tempList);
		}
	}

	SetupRepository::~SetupRepository()
	{
	}

	void SetupRepository::setAmountOfChoices(std::int32_t p_value)
	{
		mSetup.AmmountOfChoices = p_value;
		setSetup(mSetup);
	}

	void SetupRepository::setMaxRange(std::int32_t p_value)
	{
		mSetup.AmmountOfChoices = p_value;
		setSetup(mSetup);
	}

	void SetupRepository::setSetup(Setup p_setup)
	{
		// Prüfe, ob Parameter gleich mit dem gespeicherten Daten sind
		if (mSetup != p_setup)
		{
			mSetup = p_setup;
		}

		// Setupdaten in den Persistentservice schreiben
		std::vector<Setup> setupList;
		setupList.push_back(p_setup);
		mPersitenceSetupList->pushList(setupList);
		
	}

	void SetupRepository::setSetup(std::int32_t p_amountOfChoices, std::int32_t p_maxAmount)
	{
		Setup temp(p_amountOfChoices, p_maxAmount);
		setSetup(temp);
	}

	std::int32_t SetupRepository::getAmountOfChoices() const
	{
		return mSetup.AmmountOfChoices;
	}

	std::int32_t SetupRepository::getMaxRange() const
	{
		return mSetup.MaxRange;
	}
}