#ifndef __AllMembers__
#define __AllMembers__
#include <iostream>
#include"Member.h"
#include "Date.h"
#include<vector>
#pragma warning(disable: 4996)
#define new MYDEBUG_NEW
#ifdef _DEBUG 
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif // _DEBUG 
class Member;

class MembersArray
{
private:
	std::vector<Member*> membersArray;
public:
	~MembersArray();
	int getNumOfMembers()  { return membersArray.size(); } 
	Member* getMember(const std::string name) const;
	bool checkIfNameExist(const std::string name) const;
	void printAllMembers() const;
	void showLast10StatusesOfEach() const;
	void deleteMember(Member& member);
	void addMember(Member& p);
	Member* addMember(const std::string name, const Date& dateOfBirth);
};

#endif // !__AllMembers_H__

