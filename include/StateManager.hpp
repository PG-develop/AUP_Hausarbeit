#pragma once

#include <functional>
#include <map>
#include <cassert>

#include "StatesIdentifier.hpp"
#include "State.hpp"

namespace AUP_HA 
{
	/**
	* @class Steuerung der Programmzustände
	* 
	* Steuert die grundlegenenden Programmzustände.
	*/
	class StateManager 
	{
	public:
		explicit StateManager();
		~StateManager();

		template<typename T>
		void registerStates(States::ID stateID);

		void render();
		void processEvents();
		void update();


		void changeState(States::ID stateID);
		bool hasActiveState() const;

	private:
		State::Ptr											mActiveState;		/**< aktiver Zustand */
		std::map<States::ID, std::function<State::Ptr()>>	mStateFactories;	/**< Zustandsfabrik */
	};

	/**
	* @brief Registriert der Zustände in der Zustandsfabrik
	* 
	* Mithilfe eines Identifizieres werden die Zustände registriert. Es wird jedoch keine Instanz erstellt.
	* Die Registrierten Zustände können mithilfe der Methode "changeState" instantiiert werden.
	* Mithilfe des Template-Parameters wird festgelegt, welcher State instanziiert werden soll. Die Klasse muss
	* von State erben.
	* 
	* @tparam [T] State Geerbte Klasse von State
	* @param [stateID] States::ID Zustandsidentifizierer 
	*/
	template<typename T>
	inline void StateManager::registerStates(States::ID stateID)
	{
		// Füge der Fabrik eine neue Funktion hinzu, die als Rückgabewert einen neue State instanziiert.
		mStateFactories[stateID] =
			[this]()
		{
			return State::Ptr(new T(*this));
		};
	}
}