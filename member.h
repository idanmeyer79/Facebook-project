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
	std::string memberName;
	Date dateOfBirth;
	MembersArray* memberFriends;
	StatusesArray memberStatuses;
	PagesArray* memberFanPages;

public:

	Member(Member& other) = delete;
	Member(const std::string name, const Date& dateOfBirth);
	~Member();
	MembersArray& getMembersArray() { return *memberFriends; }
	StatusesArray& getStatusesArray() { return memberStatuses; }
	PagesArray& getPagesArray() { return *memberFanPages; }
	std::string getName() const;
	const Date getDate()const;
	const int getNumOfFriends() const ;
	bool setName(const std::string name);
	void setBirthDay(Date& date);
	void followPage(FanPage& fanPage);
	void showFriends() const;
	void showFanPages() const;
	void showMyStatuses() const;
	void Show10MyFriendsLastStatuses()const;
	void addFriend(Member& member);
	void addStatus();
	void addStatus(const std::string text);
	void addStatus(Status& status);
	void unFriend(Member& member);
	void printMyLast10Statuses()const;
	void disConnectPage(FanPage& page);
	bool checkFriendship(const std::string name);
	bool checkIfAlreadyFolowing(const std::string name);

	Member& operator+=(Member& other);
	Member& operator+=(FanPage& other);
	bool operator>(FanPage& other);
	bool operator>(Member& other);
};

#endif // !__MEMBER_H__
