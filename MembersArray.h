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
	int getNumOfMembers() { return numOfMembers; }
	bool checkIfNameExist(char* name);
	void addMember(Member* p); //by ref
	void printAllMembers();
	Member* getMember(char* name);
	int getNumOfUsres() { return numOfMembers; }
	void showLast10StatusesOfEach();
	void deleteMember(Member* member); //by ref
};



#endif // !__AllMembers_H__

