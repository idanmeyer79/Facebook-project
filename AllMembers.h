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
	int numOfMaxMembers = 1;

public:
	AllMembers();
	//~AllMembers();
	bool checkIfNameExist(char* name);
	void addMember(Member* p);
	void printAllMembers();
	Member* findMember(char* name);
	int getNumOfUsres() { return numOfMembers; }
};


#endif // !__AllMembers_H__

