#ifndef __PAGE_H__
#define __PAGE_H__
#include"Member.h"
#include"MembersArray.h"
#include"Status.h"
#include"StatusesArray.h"
#include <iostream>
#pragma warning(disable: 4996)

class MembersArray;
class Member;

class FanPage
{
private:
	char* pageName;
	MembersArray* fans;
	StatusesArray statuses;
	int numOfStatuses = 0;
	int numOfFans = 0;

public:
	FanPage(char* name);
	bool setName(char* name);
	char* getName();
	void addFan(Member* fan);
	void printFans();
	void removeFan(Member* fan);
	void showMyStatuses();
	void addStatus(Status& s);
	void addStatus();

};

#endif // !__PAGE_H__



