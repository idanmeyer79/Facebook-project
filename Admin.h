#ifndef __ADMIN_H__
#define __ADMIN_H__
#include "Date.h"
#include"Status.h"
#include "FanPage.h"
#include "Member.h"
#include <iostream>
#include <vector>
#include <list>
#pragma warning(disable: 4996)
#pragma warning(disable: 4267)

class FanPage;
class Member;

class Admin
{
private:
	std::list<FanPage> fanPages;
	std::list<Member>  users;
	
public:
	/**
	 * Returns a reference to the list of members.
	 *
	 * @return A reference to the list of members.
	 */
	const std::list<Member>& getMembersArray();

	/**
	 * Returns a reference to the list of members.
	 *
	 * @return A reference to the list of members.
	 */
	const std::list<Member>& getUsers() const { return users; }

	/**
	 * Returns a reference to the list of fan pages.
	 *
	 * @return A reference to the list of fan pages.
	 */
	const std::list<FanPage>& getPagesArray();

	/**
	 * Sets the list of fan pages to a new list.
	 *
	 * @param newFanPages The new list of fan pages.
	 */
	void setPagesArray(std::list<FanPage> newFanPages) { fanPages = newFanPages; }

	/**
	 * Sets the list of members to a new list.
	 *
	 * @param newUsers The new list of members.
	 */
	void setMembersArray(std::list<Member> newUsers) { users = newUsers; }

	/**
	 * Prints all members and fan pages.
	 */
	void printAccounts() const;

	/**
	 * Adds a new fan page to the list of fan pages.
	 *
	 * @param page The fan page to add.
	 */
	void addPageToFacebook(const FanPage& page);

	/**
	 * Adds a new member to the list of members.
	 *
	 * @param member The member to add.
	 */
	void addUserToFacebook(const Member& member);

	/**
	 * Makes the two given members friends.
	 *
	 * @param member1 The first member.
	 * @param member2 The second member.
	 */
	void makeFriendship(Member& member1, Member& member2);

	/**
	 * Connects the given member to the given fan page.
	 *
	 * @param member The member to connect to the fan page.
	 * @param page The fan page to connect to the member.
	 */
	void ConnectFanToPage(Member& member, FanPage& page);

	/**
	 * Removes the friendship between the two given members.
	 *
	 * @param member1 The first member.
	 * @param member2 The second member.
	 */
	void unFriendship(Member& member1, Member& member2);

	/**
	 * Disconnects the given member from the given fan page.
	 *
	 * @param member The member to disconnect from the fan page.
	 * @param page The fan page to disconnect from the member.
	 */
	void disConnectFanAndPage(Member& member, FanPage& page);

	/**
	 * Adds a new status to the given fan page.
	 *
	 * @param page The fan page to add the status to.
	 * @param status The status to add.
	 */
	void addStatusToPage(FanPage* page, const Status& status);

	/**
	 * Adds a new status to the given member.
	 *
	 * @param member The member to add the status to.
	 * @param status The status to add.
	 */
	void addStatusToMember(Member* member, const Status& status);

	/**
	 * Returns the number of members in the list of members.
	 *
	 * @return The number of members.
	 */
	int getNumOfUsers() { return users.size(); }

	/**
	 * Returns a pointer to the member with the given name, if it exists.
	 *
	 * @param name The name of the member to find.
	 * @return A pointer to the member with the given name, or `nullptr` if no such member exists.
	 */
	Member* getMember(const std::string name);

	/**
	* Returns whether there is a fan page with the given name in the list of fan pages.
	*
	* @param name The name of the fan page to check for.
	* @return `true` if there is a fan page with the given name, `false` otherwise.
	*/
	bool checkIfPageNameExist(const std::string name) const;

	/**
	* Returns whether there is a member with the given name in the list of members.
	*
	* @param name The name of the member to check for.
	* @return `true` if there is a member with the given name, `false` otherwise.
	*/
	bool checkIfUserNameExist(const std::string name) const;

	/**
	 * Prints the names of all members in the list of members.
	 */
	void printAllMembers() const;

	/**
	 * Shows the last 10 statuses of each member and fan page.
	 */
	void showLast10StatusesOfEach() const;

	/**
	 * Deletes the given member from the list of members.
	 *
	 * @param member The member to delete.
	 */
	void deleteMember(Member& member);

	/**
	 * Returns the number of fan pages in the list of fan pages.
	 *
	 * @return The number of fan pages.
	 */
	int getNumOfPages();

	/**
	 * Prints the names of all fan pages in the list of fan pages.
	 */
	void printAllPages() const;

	/**
	 * Deletes the given fan page from the list of fan pages.
	 *
	 * @param page The fan page to delete.
	 */
	void deletePage(FanPage& page);

	friend class FacebookIO;
};

#endif // !__ADMIN_H__