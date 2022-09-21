#include "../include/UserRepository.hpp"
#include "../include/TXTUserPersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	* 
	* Initialisierung
	*/
	UserRepository::UserRepository() : mUserList()
	{
		mPersistenceUserList = std::make_unique<TXTUserPersistenceListService>();
		mUserList = mPersistenceUserList->GetList();
	}

	/**
	* @brief Destruktor
	* 
	* Keien Funktion
	*/
	UserRepository::~UserRepository()
	{
	}

	/**
	* @brief Gibt das aktuelle UserRepository zur�ck.
	* 
	* @return std::vector<User> Referenz auf die Benutzerliste in sortierter Reihenfolge
	*/
	const std::vector<User>& UserRepository::GetUserSortedByRang()
	{
		return mUserList;
	}

	/**
	* @brief Versucht einen User ins Leaderboard hinzuzuf�gen.
	*		 Dabei wird gepr�ft, ob der neue User berechtigt ist,
	*		 in die Bestenliste mit aufgenommen zu werden (max. 20 Benutzer).
	* 
	* @param [user_p] User Benutzer der zum Repository hinzugef�gt werden soll
	*/
	void UserRepository::SaveOrUpdate(User user_p)
	{
		// Pr�fe, ob bereits 20 User im Leaderbord eingetragen sind
		if (mUserList.size() >= 19) {

			// Pr�fe, ob der neue User weniger Versuche als der letzte User hat.
			// Wenn dieser weniger versuche hat, entferne den letzten User.
			if (user_p.Tries < mUserList.back().Tries) {
				mUserList.pop_back();
			}
		}

		// F�ge den neuen User in das Leaderbord hinzu und sortiere die Liste neu.
		mUserList.push_back(user_p);
		std::sort(mUserList.begin(), mUserList.end(), [](User& x, User& y) {
			return x.Tries < y.Tries;
			});

		// �bergebe das UserRepository an den PersistenceListService
		mPersistenceUserList->PushList(mUserList);
	}

	/**
	* @brief L�schen des Repositories
	*/
	void UserRepository::ClearRepository()
	{
		mPersistenceUserList->Clear();
		mUserList.clear();
	}

}