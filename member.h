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
	Member(const Member& other) = delete;
	Member(const char* name, const Date& dateOfBirth);
	~Member();
	const MembersArray& getMembersArray() const  { return *memberFriends;  }
	const StatusesArray& getStatusesArray() const{ return memberStatuses;  }
	const PagesArray& getPagesArray()   const    { return *memberFanPages; }
	const char* getName() const;
	const Date getDate()const ;
	const int getNumOfFriends() const;
	bool setName(const char* name);
	void setBirthDay(Date& date);
	void followPage(FanPage& fanPage);
	void showFriends() const;
	void showFanPages() const;
	void showMyStatuses() const;
	void Show10MyFriendsLastStatuses()const;
	void addFriend(Member& member);
	void addStatus();
	void addStatus(const char* text);
	void addStatus(Status& status);
	void unFriend(Member& member);
	void printMyLast10Statuses()const;
	void disConnectPage(FanPage& page);
	bool checkFriendship(const char* name) const;
	bool checkIfAlreadyFolowing(const char* name) const;
};

#endif // !__MEMBER_H__
