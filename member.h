#ifndef __MEMBER_H__
#define __MEMBER_H__
#include "MembersArray.h"
#include "StatusesArray.h"
#include "Date.h"
#include "PagesArray.h"
#include <iostream>
#pragma warning(disable: 4996)

class PagesArray;
class MembersArray;

class Member
{
private:
	char* memberName;
	Date dateOfBirth;
	MembersArray* memberFriends;
	StatusesArray memberStatuses;
	PagesArray* memberFanPages;

public:
	Member(char* name, Date dateOfBirth);
	void setName(char* Name);
	char* getName();
	void setDate(Date date);
	Date getDate();
	void addFriend(Member* member);
	/*Member** membersRealloc(Member** arrOfPFriends, int numOfNewFriends);
	void removeFriend(Member* member1, Member* member2);*/
	void showFriends();
	void addStatus();
	void addStatus(Status& status);
	//Status** statusRealloc(Status** arrOfPStatuses, int numOfStatusesOfMember);
	/*void showFanPage();*/
	void showMyStatuses();
	/*void addFanPage(FanPage* fanPage, Member* member1);
	FanPage** fanPageRealloc(FanPage** arrOfPFanPages, int memberFanPages);
	void Show10LastStatuses(Member* member);*/
	bool checkFriendship(char* name);
};

#endif // !__MEMBER_H__
