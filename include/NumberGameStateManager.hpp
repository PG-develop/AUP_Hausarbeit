#pragma once

#include <memory>
#include <map>
#include <functional>
#include <optional>

#include "../include/NumberGameState.hpp"
#include "../include/StatesIdentifier.hpp"
#include "../include/UserRepository.hpp"
#include "../include/Game.hpp"

namespace AUP_HA
{
	/**
	* @class StateManager für die Spiellogik
	*/
	class NumberGameStateManager
	{
	public:
		typedef std::function<std::optional<GameStates::ID>(const std::string&)> TransitionHandler;

	public:
		explicit NumberGameStateManager(UserRepository& userRepository_p, Game& game_p);
		~NumberGameStateManager();

		template <typename T>
		void RegisterStates(GameStates::ID stateID_p);
		void RegisterEndGameHandler(std::function<void()> handler_p);
		
		void Render();
		void ProcessEvents();
		void Update();

		Game& GetGame();
		UserRepository& GetUserRepository();

		void ChangeState(GameStates::ID stateID_p);
		TransitionHandler& GetTransition(GameStates::TRANSITION transitionID_p);

	private:
		//TODO:: Funktionsobjekte erstellen
		void registerTransitions();
		std::optional<GameStates::ID> onEmpty(const std::string& string_p);
		std::optional<GameStates::ID> onNoNumber(const std::string& string_p);
		std::optional<GameStates::ID> onHitOrNoHit(const std::string& string_p);
		std::optional<GameStates::ID> onOutBorders(const std::string& string_p);
		std::optional<GameStates::ID> onToLeaderboard(const std::string& string_p);
		std::optional<GameStates::ID> onToIfNewGame(const std::string& string_p);
		std::optional<GameStates::ID> onNewGame(const std::string& string_p);
		std::optional<GameStates::ID> onNegativ(const std::string& string_p);
		std::optional<GameStates::ID> onWin(const std::string& string_p);

		void registerCheatCodes();

	private:
		NumberGameState::Ptr	mActiveState;		/**< Aktiver State */
		GameStates::ID			mActiveID;			/**< Aktiver Stateidentifikator */
		std::map<GameStates::ID, std::function<NumberGameState::Ptr()>> mFactory;	/**< Fabrik für die States */
		std::map<GameStates::TRANSITION, TransitionHandler> mTransitionHandlers;	/**< Übergangsbedingungsmap */
		std::map<std::int64_t, GameStates::ID>	mCheatCodes;	/**< Sonderfunktionsmap */
		std::function<void()>	mEndGame;						/**< Callback für Spielende */

		UserRepository* mUserRepository;			/**< Referenz auf das UserRepository */
		Game* mGame;								/**< Referenz auf die Spielinstanz */
	};

	/**
	* @brief Registriert der Zustände in der Zustandsfabrik
	* 
	* Mithilfe eines Identifikators werden die Zustände registriert. Es wird jedoch keine Instanz erstellt.
	* Die Registrierten Zustände können mithilfe der Methode "ChangeState" instantiiert werden.
	* Mithilfe des Template-Parameters wird festgelegt, welcher State instanziiert werden soll. Die Klasse muss
	* von State erben.
	* 
	* @tparam [T] State Geerbte Klasse von NumberGameState
	* @param [stateID_p] GameStates::ID Zustandsidentifikator 
	*/
	template<typename T>
	inline void NumberGameStateManager::RegisterStates(GameStates::ID stateID_p)
	{
		mFactory[stateID_p] =
			[this]()
		{
			return NumberGameState::Ptr(new T(*this));
		};
	}
}