#ifndef __PAGE_H__
#define __PAGE_H__
#include"Member.h"
#include"Status.h"
#include <iostream>
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
	std::vector<Status>  statuses;
	
public:
	FanPage(const std::string name) noexcept(false);
	bool setName(const std::string name);
	std::string getName() const;
	const int getNumOfFans() const;
	std::vector<Status> getStatusesArray() { return statuses; }
	std::list<Member*> getFansArray()      { return fans;     }
	void addFan(Member& fan);
	void printFans() const;
	void removeFan(Member& fan);
	void showMyStatuses();
	void addStatus(Status& s);
	void addStatus(const std::string txt); //for hard coded data
	std::vector<Status> getStatusArray() { return statuses; }
	void addStatusToArray(const Status& s);
	void printAllStatuses() const;
	int getNumOfMembers() { return fans.size(); }
	bool checkIfFanExist(const std::string& name) const;
	void printAllMembers() const;
	void deleteMember(Member& member);
	void addMember(Member& p);

	FanPage& operator+=(Member& other);
	bool operator>(FanPage& other);
	bool operator>(Member& other);
};

#endif // !__PAGE_H__



