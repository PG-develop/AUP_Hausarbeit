#include <cassert>
#include <memory>

#include "../include/NumberGameStateManager.hpp"
#include "../include/Utilities.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* �bergabe der Referenzen\n
	* Registrierung der �bergangsbedingungen in der �bergangsbedingungsmap\n
	* Registrierung der Sonderfunktionen
	* 
	* @param [userRepository_p] UserRepository 
	* @param [game_p] Spieleinstanz 
	*/
	NumberGameStateManager::NumberGameStateManager(UserRepository& userRepository_p, Game& game_p) : mCheatCodes()
	{
		// Referenz�bergabe
		mUserRepository = &userRepository_p;
		mGame = &game_p;

		// �bergangsbedingungen registrieren
		registerTransitions();

		// Sonderfunktionen registrieren
		registerCheatCodes();
	}

	/**
	* @brief Destruktor
	* 
	* Keine Funktion
	*/
	NumberGameStateManager::~NumberGameStateManager()
	{
	}

	/**
	* @brief �bergabe des Spielende-Handlers
	* 
	* Handler wird aufgerufen, sobald das Spiel beendet werden soll.
	*/
	void NumberGameStateManager::RegisterEndGameHandler(std::function<void()> handler_p)
	{
		mEndGame = handler_p;
	}

	/**
	* @brief Darstellung des aktiven GameStates
	*/
	void NumberGameStateManager::Render()
	{
		mActiveState->Render();
	}

	/**
	* @brief Benutzer- oder/und Eventeingabe des aktuellen GameStates
	*/
	void NumberGameStateManager::ProcessEvents()
	{
		mActiveState->ProcessEvents();
		
		// Der inputstream wird jedesmal nach der Benutzereingabe ges�ubert 
		Utilities::ClearInputStream();

	}

	/**
	* @brief Durchf�hrung der Logik des aktuellen GameStates
	*/
	void NumberGameStateManager::Update()
	{
		mActiveState->Update();
	}

	/**
	* @brief R�ckgabe einer Referenz der aktuellen Spieleinstanz
	* 
	* @return Game Spieleinstanz
	*/
	Game& NumberGameStateManager::GetGame()
	{
		return *mGame;
	}

	/**
	* @brief R�ckgabe einer Referenz vom UserRepository
	*/
	UserRepository& NumberGameStateManager::GetUserRepository()
	{
		return *mUserRepository;
	}

	/**
	* @brief Wechsel des GameStates
	* 
	* @param [stateID_p] GameStates::ID Identifkator
	*/
	void NumberGameStateManager::ChangeState(GameStates::ID stateID_p)
	{
		// Wenn der State "ENDE" besteht, beende das Spiel.
		if (stateID_p == GameStates::END)
		{
			// Handler muss vorab registriert werden.
			assert(mEndGame != nullptr);
			mEndGame();
		}

		// Wechsel auf einen anderen State
		else
		{
			// State muss vorab registriert sein
			auto found = mFactory.find(stateID_p);
			assert(found != mFactory.end());

			// Nur wenn sich die stateID von der aktuelle Unterscheidet, wird ein neuer State instanziiert.
			if (mActiveID != stateID_p)
			{
				mActiveID = stateID_p;
				mActiveState = found->second();
			}
		}
	}

	/**
	* @brief R�ckgabe der �bergabebedingung nach Identifikator
	* 
	* Sucht im Maphandler nach der �bergangsbedingung und gibt diese zur�ck.
	* 
	* @param [transitionID_p] GameStates::TRANSITION Identifikator
	* 
	* @return TransitionHandler& �bergangsbedingungshandler
	*/
	NumberGameStateManager::TransitionHandler& NumberGameStateManager::GetTransition(GameStates::TRANSITION transitionID_p)
	{
		auto found = mTransitionHandlers.find(transitionID_p);

		// �bergabebedinung muss vorab im Maphandler registriert sein
		assert(found != mTransitionHandlers.end());

		return found->second;
	}

	/**
	* @brief Registriert �bergangsbedingungen
	*/
	void NumberGameStateManager::registerTransitions()
	{
		mTransitionHandlers[GameStates::TRANSITION::EMPTY] = [&](const std::string& string) {
			return onEmpty(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::NN]	= [&](const std::string& string) {
			return onNoNumber(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::NH]	= [&](const std::string& string) {
			return onHitOrNoHit(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::OB]	= [&](const std::string& string) {
			return onOutBorders(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::L] = [&](const std::string& string) {
			return onToLeaderboard(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::I] = [&](const std::string& string) {
			return onToIfNewGame(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::NG] = [&](const std::string& string) {
			return onNewGame(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::C] = [&] (const std::string& string) {
			return onNegativ(string);
		};

		mTransitionHandlers[GameStates::TRANSITION::W] = [&](const std::string& string) {
			return onWin(string);
		};
	}

	/**
	* @brief �bergangsbedingnung EMPTY
	* 
	* Bei leerer String�bergabe wechsel zum GameState STATE_1\n
	* Bei nicht leerer String�bergabe wechsel zum GameState STATE_2\n
	* Wenn keine Bedinung zutrifft ist optional-Flag false
	* 
	* @param [string_p] std::string Benutzereingabe
	* 
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onEmpty(const std::string& string_p)
	{
		// pr�fe, ob String leer ist
		if (string_p.empty())
		{
			return GameStates::ID::STATE_1;
		}

		// Wenn String nicht leer ist, erstelle Usermodel und starte ein neues Spiel
		else
		{
			User user(string_p);

			mGame->NewGame(user);
			return GameStates::ID::STATE_2;
		}
	}

	/**
	* @brief �bergangsbedingnung NN
	*
	* Pr�ft, ob String�bergabe eine Nummer ist\n
	* Wenn string�bergabe keine Nummer ist, dann wechsel zum GameState STATE_3\n
	* Wenn String�bergabe eine Nummer ist, belasse das Optional-Flag auf false
	*
	* @param [string_p] std::string Benutzereingabe
	* 
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onNoNumber(const std::string& string_p)
	{
		auto parsedString = Utilities::ParseStringToInt(string_p);

		// Wenn String nicht valide ist, dann gehe �ber in GameState STATE_3
		if (!parsedString)
		{
			return GameStates::ID::STATE_3;
		}
		return std::nullopt;
	}

	/**
	* @brief �bergangsbedingnung NH
	*
	* Pr�ft, ob die Eingabe die gesuchte Zahl ist\n
	* Wenn die gesuchte Zahl gefunden wurde, dann wechsel zum GameState STATE_5\n
	* Wenn die gesuchte Zahl nicht gefunden wurde, dann wechsel zum GameState STATE_2\n
	* \n
	* Bei einer beschr�nkten Versuchsanzahl wird gepr�ft, ob die maximale Anzahl an Rateversuchen
	* erreicht ist.
	* Wenn diese erreicht wurde, wechsle zum GameState STATE_6
	*
	* @param [string_p] std::string Benutzereingabe
	* 
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onHitOrNoHit(const std::string& string_p)
	{
		// an der Stelle, muss der String definitiv eine Zahl sein.
		auto parsedString = Utilities::ParseStringToInt(string_p);

		// String war keine Zahl, wenn hier gestoppt [[DEBUG]]
		assert(parsedString);

		// Wurde die Zahl gefunden?
		if (mGame->Check(*parsedString))
		{
			return GameStates::ID::STATE_5;
		}
		
		// Nur wenn die Beschr�nkung der Versuche auf 0 gesetzt ist geht das Spiel ohne Einschr�nlung weiter.
		if (mGame->GetMaxTries() == 0)
		{
			return GameStates::ID::STATE_2;
		}
		else
		{
			// Wenn die maximale Anzahl an Versuchen erreicht ist, beende das Spiel
			if (mGame->GetMaxTries() == mGame->GetTries())
			{
				return GameStates::ID::STATE_6;
			}

			// Ansonsten zum n�chsten Versuch.
			else
			{
				return GameStates::ID::STATE_2;
			}
		}
	}

	/**
	* @brief �bergangsbedingnung W
	*
	* Pr�ft, ob die Eingabe f�r die Rateversuche gr��er 0 ist.\n
	* Wenn die Eingabe korrekt ist, wechsel zum GameState STATE_6\n
	* Wenn die Eingabe nicht korrekt ist, wechsel zum GameState STATE_9
	*
	* @param [string_p] std::string Benutzereingabe
	*
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onWin(const std::string& string)
	{
		auto parsedString = Utilities::ParseStringToInt(string);

		// Ist die Eingabe eine Zahl
		if (parsedString)
		{

			// Ist die Eingabe gr��er 0
			if (*parsedString > 0)
			{
				return GameStates::STATE_6;
			}
		}
		return GameStates::STATE_9;
	}

	/**
	* @brief �bergangsbedingnung OB
	*
	* Pr�ft, ob die Eingabe innerhalb der Spielgrenzen liegt
	* Wenn die Grenzen nicht eingehalte wurden, wechsle zum GameState STATE_4
	* Wenn die Grenzen eingehalten wurden, belasse das Optional-Flag auf false
	*
	* @param [string_p] std::string Benutzereingabe
	*
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onOutBorders(const std::string& string)
	{
		// Hole die Grenzen aus der Spieleinstanz
		auto limits = std::make_pair<const std::int32_t&, const std::int32_t&>(mGame->GetMinBorder(), mGame->GetMaxBorder());

		// parse die Eingabe mit den Grenzen
		auto parsedString = Utilities::ParseStringToIntWithLimits(string, limits);

		// Pr�fe, ob die Grenzen nicht eingehalten wurden
		// !!! Die Pr�fung, ob es eine Zahl ist muss in einer �bergangsbedingung davor bereits gepr�ft sein.
		if (!parsedString)
		{
			return GameStates::ID::STATE_4;
		}
		return std::nullopt;
	}

	/**
	* @brief �bergangsbedingnung L
	*
	* Wechsel zum GameSTate STATE_6
	*
	* @param [string_p] std::string Benutzereingabe
	*
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onToLeaderboard(const std::string& string)
	{
		return GameStates::STATE_6;
	}


	/**
	* @brief �bergangsbedingnung I
	*
	* Wechsel zum GameSTate STATE_7
	*
	* @param [string_p] std::string Benutzereingabe
	*
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onToIfNewGame(const std::string& string)
	{
		return GameStates::STATE_7;
	}


	/**
	* @brief �bergangsbedingnung NG
	*
	* Wenn der �bergabeString das Zeichen j ist, wechsle zum GameState STATE_1\n
	* Wenn der �bergabeString das Zeichen n ist, wechsle zum GameState END\n
	* Wenn keines der Zeichen �bergeben wurde, belasse das Optional-Flag auf false
	*
	* @param [string_p] std::string Benutzereingabe
	*
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onNewGame(const std::string& string)
	{
		// pr�fe, ob der String ein 'j' ist
		if (string.compare("j") == 0)
		{
			return GameStates::STATE_1;
		}
		
		// pr�fe, ob der String ein 'n' ist
		if (string.compare("n") == 0)
		{
			return GameStates::END;
		}
		return std::nullopt;
	}

	/**
	* @brief �bergangsbedingnung C
	*
	* Auswertung von Negativen Zahlen (Sonderfunktionen)\n
	* Wenn keine Sonderfunktion getroffen wurde, wechsle zum GameState STATE_6\n
	* Wenn eine Sonderfunktion getroffen wurde, dann wechsel zum Gamstate, der der Sonderfunktion zugeordnet ist\n
	* Wenn keine negative Zahl eingebene wurde, belasse das Optional-Flag auf false
	*
	* @param [string_p] std::string Benutzereingabe
	*
	* @return std::optional<GameState::ID> Identifikator f�r n�chsten GameState\n
	* ansonsten optional-Falg false
	*/
	std::optional<GameStates::ID> NumberGameStateManager::onNegativ(const std::string& string)
	{
		auto parsedString = Utilities::ParseStringToInt(string);

		// pr�fe, ob die Eingabe eine negative Zahl ist
		if (*parsedString < 0)
		{
			// Pr�fe, ob es einen Sonderfunktion gibt
			auto founded = mCheatCodes.find(*parsedString);

			// f�hre die Sonderfunktion aus
			if (founded != mCheatCodes.end())
			{
				return founded->second;
			}

			// Wenn es keinen  Sonderfunktion gibt, beende das Spiel
			return GameStates::STATE_6;
		}

		return std::nullopt;
	}

	/**
	* @brief Registrierung von Sonderfunktionszahlen (negative)
	* 
	* Sonderfunktionszahlen m�ssen negativ sein.
	*/
	void NumberGameStateManager::registerCheatCodes()
	{
		mCheatCodes[-123] = GameStates::STATE_8;
		mCheatCodes[-456] = GameStates::STATE_9;
	}
}