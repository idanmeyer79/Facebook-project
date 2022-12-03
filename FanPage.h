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
public:
	static constexpr int LEN_OF_STATUS = 100;
	static constexpr int LEN_OF_NAME = 20;

private:
	char* pageName;
	MembersArray* fans;
	StatusesArray statuses;
	
public:
	FanPage(FanPage& other) = delete;
	FanPage(const char* name);
	~FanPage();
	bool setName(const char* name);
	char* getName();
	int getNumOfFans();
	StatusesArray& getStatusesArray() { return statuses; }
	MembersArray& getFansArray() { return *fans; }
	void addFan(Member& fan);
	void printFans();
	void removeFan(Member& fan);
	void showMyStatuses();
	void addStatus(Status& s);
	void addStatus();
	void addStatus(const char* txt);
};

#endif // !__PAGE_H__



