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
	MembersArray(const MembersArray& other) = delete;
	MembersArray();
	~MembersArray();
	const int getNumOfMembers() const  { return numOfMembers;    }
	const int getNumOfMaxMembrs() const { return numOfMaxMembers; }
	Member* getMember(const char* name) const;
	bool checkIfNameExist(const char* name) const ;
	void printAllMembers() const;
	void showLast10StatusesOfEach() const;
	void deleteMember(Member& member);
	void addMember(Member& p);
	Member* addMember(const char* name, const Date& dateOfBirth);
};

#endif // !__AllMembers_H__

