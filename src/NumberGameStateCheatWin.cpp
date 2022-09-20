#include <chrono>

#include "../include/NumberGameStateCheatWin.hpp"
#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"
#include "../include/UserRepository.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*
	* Laden der �bergangsbedingungen: W
	*/
	NumberGameStateCheatWin::NumberGameStateCheatWin(NumberGameStateManager& manager_p) : NumberGameState(manager_p)
	{
		mTransitionList.push_back(manager_p.GetTransition(GameStates::TRANSITION::W));

		// Hole eine Referenz auf das UserRepository vom NumberGameStateManager
		mUserRepository = &manager_p.GetUserRepository();
	}

	/**
	* @Destruktor
	*
	* Keine Funktion
	*/
	NumberGameStateCheatWin::~NumberGameStateCheatWin()
	{
	}

	/**
	* @brief Spielanzeige
	*
	* Es wird gefragt, wie viele Rateversuche f�r die Bestenliste aufgenommen werden soll
	*/
	void NumberGameStateCheatWin::Render()
	{
		std::cout << "Gewonnen!" << std::endl;
		std::cout << "Wie viele Versuche sollen eingetragen werden? ";

	}

	/**
	* @brief Benutzereingabe
	*/
	void NumberGameStateCheatWin::ProcessEvents()
	{
		std::cin >> mInputBuffer;
		
	}

	/**
	* @brief Ausf�hrung der Logik
	*
	* Benuzereingabe wird geparst\n
	* Usermodel wird f�r das Spiel mit Daten belegt
	*/
	void NumberGameStateCheatWin::Update()
	{
		auto parsedString = Utilities::ParseStringToInt(mInputBuffer);

		// Wenn der String in Ordnung ist, wird das Usermodel mit den Daten parametriert.
		// Wenn der String nicht geparst werden konnte, erfolgt keine Transition
		if (parsedString)
		{
			// User aus dem Spiel anfragen
			User user = mGame->GetUser();
			
			// Versuchsanzahl ans Usermodel �bergeben 
			user.Tries = *parsedString;

			// Zeit muss koh�rent behandelt werden, daher eine eingabe an das Usermodel und an das Spiel
			// Das Spiel muss f�r die Bestenliste die Zeit kennen
			user.Date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			mGame->SetNewTime(user.Date);

			// Usermodel an das UserRepository �bergeben
			mUserRepository->SaveOrUpdate(user);
		}

		// pr�ft �bergangsbedingungen
		checkTransitions();
	}
}