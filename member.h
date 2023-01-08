#ifndef __MEMBER_H__
#define __MEMBER_H__
#include "Date.h"
#include "FanPage.h"
#include"status.h"
#include <iostream>
#include<vector>
#include<list>
#pragma warning(disable: 4996)

class PagesArray;
class MembersArray;
class FanPage;

class Member
{
private:
	std::string memberName;
	Date dateOfBirth;
	std::vector<Status*> memberStatuses;
	std::list<FanPage*> memberFanPages;
	std::list<Member*>  memberFriends;

public:
	Member(const std::string name, const Date& dateOfBirth);
	std::list<Member*> getMembersArray()   { return memberFriends;  }
	std::vector<Status*> getStatusesArray() { return memberStatuses; }
	std::list<FanPage*> getPagesArray()    { return memberFanPages; }
	int getNumOfPages()                    { return memberFanPages.size(); }
	int getNumOfMembers()                  { return memberFriends.size(); }
	std::vector<Status*> getStatusArray()   { return memberStatuses; }
	std::string getName() const;
	const Date getDate()const;
	const int getNumOfFriends() const ;
	bool setName(const std::string name);
	void setBirthDay(Date& date);

	/**
	* Adds a new fan page to the list of followed fan pages.
	*
	* @param fanPage The fan page to follow.
	*/
	void followPage(FanPage& fanPage);

	/**
	 * Shows the names of all friends.
	 */
	void showFriends() const;

	/**
	 * Shows the names of all followed fan pages.
	 */
	void showFanPages() const;

	/**
	 * Shows the statuses of the member.
	 */
	void showMyStatuses() const;

	/**
	 * Adds a new friend to the list of friends.
	 * @param member The friend to add.
	 */
	void addFriend(Member& member);

	/**
	 * Adds a new status to the vector of statuses, with the given text.
	 * @param text The text of the status to add.
	 */
	void addStatus(const std::string text);

	/**
	 * Adds a new status to the vector of statuses.
	 * @param status The status to add.
	 */
	void addStatus(Status* status);

	/**
	* Removes a friend from the list of friends.
	* @param member The friend to remove.
	*/
	void unFriend(Member& member);

	/**
	 * Shows the member's last 10 statuses.
	 */
	void printMyLast10Statuses() const;

	/**
	 * Removes a fan page from the list of followed fan pages.
	 * @param page The fan page to remove.
	 */
	void disConnectPage(FanPage& page);

	/**
	 * Returns whether the member is friends with the member with the given name.
	 * @param name The name of the member to check for.
	 * @return `true` if the member is friends with the member with the given name, `false` otherwise.
	 */
	bool checkFriendship(const std::string name);

	/**
	 * Returns whether the member is already following the fan page with the given name.
	 * @param name The name of the fan page to check for.
	 * @return `true` if the member is already following the fan page with the given name, `false` otherwise.
	 */
	bool checkIfAlreadyFolowing(const std::string name);

	//From pages Array

	/**
	* Adds a new fan page to the list of fan pages.
	* @param p The fan page to add.
	*/
	void addPage(FanPage& p);

	/**
	 * Shows the names of all fan pages.
	 */
	void printAllPages() const;

	/**
	 * Finds a fan page with the given name and returns a pointer to it.
	 * @param name The name of the fan page to find.
	 * @return A pointer to the fan page with the given name, or `nullptr` if no such fan page exists.
	 */
	FanPage* findPage(std::string name);

	/**
	 * Returns whether a member with the given name exists.
	 * @param name The name of the member to check for.
	 * @return `true` if a member with the given name exists, `false` otherwise.
	 */
	bool checkIfMemberNameExist(const std::string& name) const;

	/**
	* Deletes a fan page from the list of fan pages.
	* @param page The fan page to delete.
	*/
	void deletePage(FanPage& page);

	//from members array

	/**
	* Returns a pointer to the member with the given name, if it exists.
	*
	* @param name The name of the member to find.
	* @return A pointer to the member with the given name, or `nullptr` if no such member exists.
	*/
	Member* getMember(const std::string name);

	/**
	 * Shows the names of all members.
	 */
	void printAllMembers() const;

	/**
	 * Shows the last 10 statuses of each friend.
	 */
	void showLast10StatusesOfEach() const;

	/**
	 * Deletes a member from the list of members.
	 *
	 * @param member The member to delete.
	 */
	void deleteMember(Member& member);

	//from statuses array

	/**
	 * Shows all statuses.
	 */
	void printAllStatuses() const;

	/**
	 * Shows the last 10 statuses.
	 */
	void print10() const;

	/**
	 * Adds a new friend to the list of friends and returns a reference to this member.
	 *
	 * @param other The friend to add.
	 * @return A reference to this member.
	 */
	Member& operator+=(Member& other);

	/**
	 * Adds a new followed fan page to the list of followed fan pages and returns a reference to this member.
	 *
	 * @param other The fan page to follow.
	 * @return A reference to this member.
	 */
	Member& operator+=(FanPage& other);

	/**
	 * Compares this member to a fan page based on the number of friends.
	 *
	 * @param other The fan page to compare to.
	 * @return `true` if this member has more friends than the fan page, `false` otherwise.
	 */
	bool operator>(FanPage& other);

	/**
	 * Compares this member to another member based on the number of friends.
	 *
	 * @param other The other member to compare to.
	 * @return `true` if this member has more friends than the other member, `false` otherwise.
	 */
	bool operator>(Member& other);

};

#endif // !__MEMBER_H__