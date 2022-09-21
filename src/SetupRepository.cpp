#include <vector>

#include "../include/SetupRepository.hpp"
#include "../include/TXTSetupPersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Initialisierung
	*/
	SetupRepository::SetupRepository() : mSetup()
	{
		// PersistenceListService instanziieren
		mPersitenceSetupList = std::make_unique<TXTSetupPersistenceListService>();
		
		// Setupdaten aus dem Persistentservice laden
		std::vector<Setup> tempList = mPersitenceSetupList->GetList();

		// Pr�fe, ob Setupdaten vorhanden sind
		if (tempList.size() == 1)
		{
			mSetup = tempList[0];
		}

		// Wenn keine Daten existieren, initialisiere mit Werksdaten
		else
		{
			mSetup.AmmountOfChoices = 0;
			mSetup.MaxRange = 1000;

			// Daten an den Service �bergeben
			tempList.push_back(mSetup);
			mPersitenceSetupList->PushList(tempList);
		}
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	SetupRepository::~SetupRepository()
	{
	}

	/**
	* @brief �ndern der Versuchsanzahl
	* 
	* @param [value_p] std::int32_t Versuchsanzahl
	*/
	void SetupRepository::SetAmountOfChoices(std::int32_t value_p)
	{
		mSetup.AmmountOfChoices = value_p;
		SetSetup(mSetup);
	}

	/**
	* @brief �ndern der Streureichweite
	* 
	* @param [value_p] std::int32_t Streureichweite
	*/
	void SetupRepository::SetMaxRange(std::int32_t value_p)
	{
		mSetup.MaxRange = value_p;
		SetSetup(mSetup);
	}

	/**
	* @brief Neues SetupModel initialisieren
	* 
	* @param [setup_p] Setup Model f�r neues Setup
	*/
	void SetupRepository::SetSetup(Setup setup_p)
	{
		// Pr�fe, ob Parameter nicht gleich mit dem gespeicherten Daten sind
		if (mSetup != setup_p)
		{
			mSetup = setup_p;
		}

		// Setupdaten in den Persistentservice schreiben
		// Model muss in ein Vector f�r den Service gelegt werden
		std::vector<Setup> setupList;
		setupList.push_back(setup_p);
		mPersitenceSetupList->PushList(setupList);
		
	}

	/**
	* @brief Neues SetupModel initialisieren
	* 
	* @param [amountOfChoices_p] std::int32_t Versuchsanzahl
	* @param [maxAmount_p] std::int32_t Streureichweite
	*/
	void SetupRepository::SetSetup(std::int32_t amountOfChoices_p, std::int32_t maxAmount_p)
	{
		Setup temp(amountOfChoices_p, maxAmount_p);
		SetSetup(temp);
	}

	/**
	* @brief R�ckgabe der erlaubten Versuchsanzahlen
	* 
	* @return std::int32_t Versuchsanzahlen
	*/
	std::int32_t SetupRepository::GetAmountOfChoices() const
	{
		return mSetup.AmmountOfChoices;
	}

	/**
	* @brief R�ckgabe der Streureichweite
	* 
	* @return std::int32_t Streureichweite
	*/
	std::int32_t SetupRepository::GetMaxRange() const
	{
		return mSetup.MaxRange;
	}
}