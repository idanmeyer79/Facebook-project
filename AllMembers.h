#ifndef __AllMembers__
#define __AllMembers__
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;
#include"Member.h"

class AllMembers
{
private:
	Member** allMembers;
	int numOfMembers = 0;

public:
	void addMember(Member& p);
	void printAllMembers();
	Member* findMember(char* name);
};


#endif // !__AllMembers_H__

