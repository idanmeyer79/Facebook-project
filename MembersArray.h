#ifndef __AllMembers__
#define __AllMembers__
#include <iostream>
#pragma warning(disable: 4996)
#include"Member.h"

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
	bool checkIfNameExist(char* name);
	void addMember(Member* p);
	void printAllMembers();
	Member* getMember(char* name);
	int getNumOfUsres() { return numOfMembers; }
};


#endif // !__AllMembers_H__

