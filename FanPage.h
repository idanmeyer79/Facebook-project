#ifndef __PAGE_H__
#define __PAGE_H__
#include"Member.h"
#include"MembersArray.h"
#include"Status.h"
#include"StatusesArray.h"
#include <iostream>
#pragma warning(disable: 4996)
#define new MYDEBUG_NEW
#ifdef _DEBUG 
#define MYDEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define MYDEBUG_NEW new
#endif // _DEBUG 
class MembersArray;
class Member;

class FanPage
{
private:
	std::string pageName;
	MembersArray* fans;
	StatusesArray statuses;
	
public:
	FanPage(FanPage& other) = delete;
	FanPage(const std::string name);
	~FanPage();
	bool setName(const std::string name);
	std::string getName() const;
	const int getNumOfFans() const;
	StatusesArray& getStatusesArray() { return statuses; }
	MembersArray& getFansArray() { return *fans; }
	void addFan(Member& fan);
	void printFans() const;
	void removeFan(Member& fan);
	void showMyStatuses();
	void addStatus(Status& s);
	void addStatus();
	void addStatus(const std::string txt);
	FanPage& operator+=(Member& other);
	bool operator>(FanPage& other);
	bool operator>(Member& other);

};

#endif // !__PAGE_H__



