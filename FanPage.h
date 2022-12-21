#ifndef __PAGE_H__
#define __PAGE_H__
#include"Member.h"
#include"MembersArray.h"
#include"Status.h"
#include"StatusesArray.h"
#include <iostream>
#include<vector>
#pragma warning(disable: 4996)

class MembersArray;
class Member;

class FanPage
{
public:
	static constexpr int LEN_OF_STATUS = 100;
	static constexpr int LEN_OF_NAME = 20;

private:
	std::string pageName;
	std::vector<Member*> fans;
	std::vector<Status> statuses;
	//MembersArray* fans;
	//StatusesArray statuses;
	
public:
	FanPage(const std::string name);
	//~FanPage();
	bool setName(const std::string name);
	std::string getName() const;
	const int getNumOfFans() const;
	std::vector<Status> getStatusesArray() { return statuses; }
	std::vector<Member*> getFansArray()     { return fans; }
	void addFan(Member& fan);
	void printFans() const;
	void removeFan(Member& fan);
	void showMyStatuses();
	void addStatus(Status& s);
	void addStatus();
	void addStatus(const std::string txt);
	//operators overload
	FanPage& operator+=(Member& other);
	bool operator>(FanPage& other);
	bool operator>(Member& other);
	//from statuses array
	std::vector<Status> getStatusArray() { return statuses; }
	void addStatusToArray(Status& s);
	void printAllStatuses() const;
	//from members array
	int getNumOfMembers() { return fans.size(); }
	bool checkIfNameExist(const std::string name) const;
	void printAllMembers() const;
	void deleteMember(Member& member);
	void addMember(Member& p);

};

#endif // !__PAGE_H__



