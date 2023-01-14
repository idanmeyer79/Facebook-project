#ifndef __PAGE_H__
#define __PAGE_H__
#include"Member.h"
#include"Status.h"
#include"StatusWithPhoto.h"
#include"StatusWithVideo.h"
#include <iostream>
#include <fstream>
#include<vector>
#include<list>
#pragma warning(disable: 4996)

class MembersArray;
class Member;

class FanPage
{
private:
	std::string          pageName;
	std::list<Member*>   fans;
	std::vector<Status*>  statuses;
	
public:
	FanPage(std::ifstream& file);
	std::list<Member*> getFans() const;
	std::vector<Status*>  getStatuses() const { return statuses; }
	int  getNumOfStatuses() const { return statuses.size(); }
	void addFans(std::list<Member*>   newFans) { fans = newFans; }
	void addStatuses(std::vector<Status*>   newstatuses) { statuses = newstatuses; }

	//bool operator==(const FanPage& other) const { return pageName == other.pageName; }
		
	bool operator==(const FanPage& other) const	{return pageName == other.pageName;	}
	bool operator==(const FanPage* other) const	{return pageName == other->pageName;	}



	/**
	 * Constructs a new fan page with the given name.
	 *
	 * @param name The name of the fan page.
	 */
	FanPage(const std::string name);

	/**
	 * Sets the name of the fan page.
	 *
	 * @param name The new name of the fan page.
	 * @return `true` if the name was set successfully, `false` otherwise.
	 */
	bool setName(const std::string name);

	/**
	 * Returns the name of the fan page.
	 *
	 * @return The name of the fan page.
	 */
	std::string getName() const;

	/**
	 * Returns the number of fans of the fan page.
	 *
	 * @return The number of fans of the fan page.
	 */
	const int getNumOfFans() const { return fans.size(); }

	/**
	 * Returns a reference to the list of statuses.
	 *
	 * @return A reference to the list of statuses.
	 */
	std::vector<Status*>& getStatusesArray() { return statuses; }

	/**
	 * Returns a reference to the list of fans.
	 *
	 * @return A reference to the list of fans.
	 */
	std::list<Member*>& getFansArray() { return fans; }

	/**
	 * Returns a reference to the list of statuses.
	 *
	 * @return A reference to the list of statuses.
	 */
	std::vector<Status*>& getStatusArray() { return statuses; }


	/**
	 * Adds a new fan to the list of fans.
	 *
	 * @param fan The fan to add.
	 */
	void addFan(Member& fan);

	/**
	 * Prints the names of all fans.
	 */
	void printFans() const;

	/**
	 * Removes a fan from the list of fans.
	 *
	 * @param fan The fan to remove.
	 */
	void removeFan(Member& fan);

	/**
	 * Shows the statuses of this fan page.
	 */
	void showMyStatuses();

	/**
	 * Adds a new status to the vector of statuses, with the given text.
	 *
	 * @param txt The text of the status to add.
	 */
	void addStatus(std::string txt);

	/**
	 * Adds a new status to the vector of statuses.
	 *
	 * @param s The status to add.
	 */
	void addStatusToArray(Status* s);

	/**
	 * Prints all statuses.
	 */
	void printAllStatuses() const;

	/**
	 * Returns whether the given fan is in the list of fans.
	 *
	 * @param name The name of the fan to check for.
	 * @return `true` if the fan is in the list of fans, `false` otherwise.
	 */
	bool checkIfFanExist(const std::string& name) const;

	/**
	 * Prints the names of all members in the list of members.
	 */
	void printAllMembers() const;

	/**
	 * Deletes a member from the list of fans.
	 *
	 * @param member The member to delete.
	 */
	void deleteMember(Member& member);

	/**
	 * Adds a new member to the list of fans.
	 *
	 * @param p The member to add.
	 */
	void addMember(Member& p);

	
	/**
	 * Adds a new fan to the list of fans and returns a reference to this fan page.
	 *
	 * @param other The fan to add.
	 * @return A reference to this fan page.
	 */
	FanPage& operator+=(Member& other);

	/**
	 * Compares this fan page to another fan page based on the number of fans.
	 *
	 * @param other The other fan page to compare to.
	 * @return `true` if this fan page has more fans than the other fan page, `false` otherwise.
	 */
	bool operator>(FanPage& other);

	/**
	 * Compares this fan page to a member based on the number of fans.
	 *
	 * @param other The member to compare to.
	 * @return `true` if this fan page has more fans than the member, `false` otherwise.
	 */
	bool operator>(Member& other);

	void saveToFile(std::ofstream& outFile) const;

	friend class Admin;

};

#endif // !__PAGE_H__



