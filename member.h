#ifndef __MEMBER_H__
#define __MEMBER_H__
#include "MembersArray.h"
#include "StatusesArray.h"
#include "Date.h"
#include "PagesArray.h"
#include "FanPage.h"
#include <iostream>
#pragma warning(disable: 4996)

class PagesArray;
class MembersArray;
class FanPage;

class Member
{
private:
	char* memberName;
	Date dateOfBirth;
	MembersArray* memberFriends;
	StatusesArray memberStatuses;
	PagesArray* memberFanPages;

public:
	Member(const char* name, const Date& dateOfBirth);
	void setName(const char* Name);
	char* getName();
	void setBirthDay(Date& date);
	Date getDate();
	void addFriend(Member& member);
	void followPage(FanPage& fanPage);
	int getNumOfFriends();
	void showFriends();
	void showFanPages();
	void addStatus();
	void addStatus(Status& status);
	void showMyStatuses();
	void unFriend(Member& member);
	void Show10MyFriendsLastStatuses();
	void printMyLast10Statuses();
	bool checkFriendship(const char* name);
	void disConnectPage(FanPage& page);
	bool checkIfAlreadyFolowing(const char* name);
	void addStatus(const char* text);
};

#endif // !__MEMBER_H__
