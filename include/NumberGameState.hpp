#pragma once

#include <memory>
#include <string>
#include <optional>
#include <vector>
#include <functional>

#include "../include/StatesIdentifier.hpp"
#include "../include/Game.hpp"

namespace AUP_HA
{
	// Vorw�rtsdeklaration
	class NumberGameStateManager;

	/**
	* @class NumberGameState
	* @brief Basisklasse f�r NumberGameStates
	*/
	class NumberGameState
	{
	public:
		typedef std::unique_ptr<NumberGameState> Ptr;

	public:
		NumberGameState(NumberGameStateManager& manager_p);
		virtual ~NumberGameState();

		virtual void Render() = 0;
		virtual void ProcessEvents() = 0;
		virtual void Update() = 0;

	protected:
		void requestChange(GameStates::ID stateID_p);
		void checkTransitions();

	protected:
		std::string mInputBuffer;	/**< Eingabepuffer */
		Game* mGame;				/**< Referenz auf Spieleinstanz */

		// In dem Vector werden Funktionen gespeichert, in denen die Transitionbedingungen gepr�ft werden.
		std::vector<std::function<std::optional<GameStates::ID>(const std::string&)>> mTransitionList; /**< �bergangsbedingungsliste */

	private:
		NumberGameStateManager* mManager;	/**< Referenz auf den NumberGameStateManager */
	};
}