#pragma once

#include <memory>
#include <string>

#include "../include/State.hpp"
#include "../include/MenuManager.hpp"
#include "../include/MenuIdentifier.hpp"

namespace AUP_HA
{
	// Vorwärtsdeklaration
	class SetupRepository;

	/**
	* @class SetupGameState
	* @brief Spieleinstellungen State
	* 
	* Dem Benutzer soll ermöglicht werden, die Spieleinstellungen zu konfigurieren.
	*/
	class SetupGameState : public State
	{
	public:
		SetupGameState(StateManager& stateManager_p);
		virtual ~SetupGameState();

		virtual void Render();
		virtual void ProcessEvents();
		virtual void Update();

	private:
		void registerMenu();

		void onChangeAmountOfChoices();
		void onChangeMaxRange();
		void onExit();

	private:
		std::string							mUserinput;			/**< Eingabe des Benutzers */
		std::unique_ptr<SetupRepository>	mSetupRepository;	/**< SetupRepository */
		MenuManager<SETUP_GAMESETUP::ID>	mMenu;				/**< Menustruktur */
		std::pair<std::int32_t, std::int32_t> mLimits;			/**< Limitierung für das Menu */
	};
}