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
	Member(char* name, Date dateOfBirth); //by ref
	void setName(char* Name);
	char* getName();
	void setDate(Date date); //by ref
	Date getDate();
	void addFriend(Member* member); //by ref
	void followPage(FanPage* fanPage); //by ref
	int getNumOfFriends();
	void showFriends();
	void showFanPages();
	void addStatus();
	void addStatus(Status& status); //by ref
	void showMyStatuses();
	void unFriend(Member* member); //by ref
	void Show10MyFriendsLastStatuses();
	void printMyLast10Statuses();
	bool checkFriendship(char* name);
	void disConnectPage(FanPage* page);
	bool checkIfAlreadyFolowing(char* name);
};

#endif // !__MEMBER_H__
