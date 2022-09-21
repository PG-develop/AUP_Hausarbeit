#pragma once

#include <functional>
#include <map>
#include <cassert>

#include "StatesIdentifier.hpp"
#include "State.hpp"

namespace AUP_HA 
{
	/**
	* @class StateManager
	* @brief Steuerung der Programmzustände Grundgerüst
	* 
	* Steuert die grundlegenenden Programmzustände.
	*/
	class StateManager 
	{
	public:
		explicit StateManager();
		~StateManager();

		template<typename T>
		void registerStates(States::ID stateID_p);

		void Render();
		void ProcessEvents();
		void Update();


		void changeState(States::ID stateID_p);
		bool hasActiveState() const;

	private:
		State::Ptr											mActiveState;		/**< aktiver Zustand */
		std::map<States::ID, std::function<State::Ptr()>>	mStateFactories;	/**< Zustandsfabrik */
	};

	/**
	* @brief Registriert der Zustände in der Zustandsfabrik
	* 
	* Mithilfe eines Identifikators werden die Zustände registriert. Es wird jedoch keine Instanz erstellt.
	* Die Registrierten Zustände können mithilfe der Methode "ChangeState" instantiiert werden.
	* Mithilfe des Template-Parameters wird festgelegt, welcher State instanziiert werden soll. Die Klasse muss
	* von State erben.
	* 
	* @tparam [T] State Geerbte Klasse von State
	* @param [stateID_p] States::ID Zustandsidentifikator 
	*/
	template<typename T>
	inline void StateManager::registerStates(States::ID stateID_p)
	{
		// Füge der Fabrik eine neue Funktion hinzu, die als Rückgabewert einen neue State instanziiert.
		mStateFactories[stateID_p] =
			[this]()
		{
			return State::Ptr(new T(*this));
		};
	}
}