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
public:
	static constexpr int LEN_OF_STATUS = 100;
	static constexpr int LEN_OF_NAME = 20;

private:
	char* memberName;
	Date dateOfBirth;
	MembersArray* memberFriends;
	StatusesArray memberStatuses;
	PagesArray* memberFanPages;

public:
	Member(Member& other) = delete;
	Member(const char* name, const Date& dateOfBirth);
	~Member();
	void setName(const char* Name);
	char* getName();
	void setBirthDay(Date& date);
	Date getDate();
	int getNumOfFriends();
	void followPage(FanPage& fanPage);
	void showFriends();
	void showFanPages();
	void showMyStatuses();
	void Show10MyFriendsLastStatuses();
	void addFriend(Member& member);
	void addStatus();
	void addStatus(const char* text);
	void addStatus(Status& status);
	void unFriend(Member& member);
	void printMyLast10Statuses();
	void disConnectPage(FanPage& page);
	bool checkFriendship(const char* name);
	bool checkIfAlreadyFolowing(const char* name);
};

#endif // !__MEMBER_H__
