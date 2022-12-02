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
	
public:
	FanPage(const char* name);
	bool setName(const char* name);
	char* getName();
	int getNumOfFans();
	void addFan(Member& fan);
	void printFans();
	void removeFan(Member& fan);
	void showMyStatuses();
	void addStatus(Status& s);
	void addStatus();
	Status& addStatus(const char* txt);
};

#endif // !__PAGE_H__



