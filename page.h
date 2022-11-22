#ifndef __PAGE_H__
#define __PAGE_H__
#include"Member.h"
#include"Status.h"
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

class Member;

class FanPage
{
private:
	char* pageName;
	Member** fans;
	Status** statuses;
	int numOfStatuses = 0;
	int numOfFans = 0;

public:
	FanPage(char* name);
	bool setName(char* name);
	char* getName();
	void addFan(Member* fan);
	void printFans();
	void removeFan(Member* fan);
	void printAllStatuses();
	void addStatus(char* text);
};

#endif // !__PAGE_H__



