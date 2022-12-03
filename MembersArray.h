#ifndef __AllMembers__
#define __AllMembers__
#include <iostream>
#pragma warning(disable: 4996)
#include"Member.h"
#include "Date.h"

class Member;

class MembersArray
{
private:
	Member** membersArray;
	int numOfMembers = 0;
	int numOfMaxMembers = 1;

public:
	MembersArray();
	//~MembersArray();
	int getNumOfMembers() { return numOfMembers; }
	bool checkIfNameExist(const char* name);
	void addMember(Member& p);
	void printAllMembers();
	Member* getMember(const char* name);
	int getNumOfUsres() { return numOfMembers; }
	void showLast10StatusesOfEach();
	void deleteMember(Member& member);
	Member* addMember(const char* name, const Date& dateOfBirth);
};



#endif // !__AllMembers_H__

