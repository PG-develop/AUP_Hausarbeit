#include "../include/UserRepository.hpp"
#include "../include/TXTUserPersistenceListService.hpp"

namespace AUP_HA
{
	/**
	* @brief Konstruktor
	*/
	UserRepository::UserRepository() : mUserList()
	{
		mPersistenceUserList = std::make_unique<TXTUserPersistenceListService>();
		mUserList = mPersistenceUserList->getList();
	}

	/**
	* @brief Destruktor
	*/
	UserRepository::~UserRepository()
	{
	}

	/**
	* @brief Gibt das aktuelle UserRepository zurück.
	*/
	const std::vector<User>& UserRepository::GetUserSortedByRang()
	{
		return mUserList;
	}

	/**
	* @brief Versucht einen User ins Leaderboard hinzuzufügen.
	*		 Dabei wird geprüft, ob der neue User berechtigt ist,
	*		 in die Bestenliste mit aufgenommen zu werden.
	*/
	void UserRepository::SaveOrUpdate(User user)
	{
		// Prüfe, ob bereits 20 User im Leaderbord eingetragen sind
		if (mUserList.size() > 20) {

			// Prüfe, ob der neue User weniger Versuche als der letzte User hat.
			// Wenn dieser weniger versuche hat, entferne den letzten User.
			if (user.Tries < mUserList.back().Tries) {
				mUserList.pop_back();
			}
		}

		// Füge den neuen User in das Leaderbord hinzu und sortiere die Liste neu.
		mUserList.push_back(user);
		std::sort(mUserList.begin(), mUserList.end(), [](User& x, User& y) {
			return x.Tries < y.Tries;
			});

		// Übergebe das UserRepository an den PersistenceListService
		mPersistenceUserList->pushList(mUserList);
	}

}