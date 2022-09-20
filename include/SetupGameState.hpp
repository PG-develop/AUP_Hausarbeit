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
	* 
	* Dem Benurter soll ermöglicht werden, die Spieleinstellungen zu konfigurieren.
	*/
	class SetupGameState : public State
	{
	public:
		SetupGameState(StateManager& stateManager);
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
		std::string							mUserinput;
		std::unique_ptr<SetupRepository>	mSetupRepository;
		MenuManager<SETUP_GAMESETUP::ID>	mMenu;
		std::pair<std::int32_t, std::int32_t> mLimits;
	};
}