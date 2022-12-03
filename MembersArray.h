#ifndef __AllMembers__
#define __AllMembers__
#include <iostream>
#include"Member.h"
#include "Date.h"
#pragma warning(disable: 4996)

class Member;

class MembersArray
{
private:
	Member** membersArray;
	int numOfMembers = 0;
	int numOfMaxMembers = 1;

public:
	MembersArray(MembersArray& other) = delete;
	MembersArray();
	~MembersArray();
	int getNumOfMembers()   { return numOfMembers; }
	int getNumOfMaxMembrs() { return numOfMaxMembers; }
	Member* getMember(const char* name);
	bool checkIfNameExist(const char* name);
	void printAllMembers();
	void showLast10StatusesOfEach();
	void deleteMember(Member& member);
	void addMember(Member& p);
	Member* addMember(const char* name, const Date& dateOfBirth);
};

#endif // !__AllMembers_H__

