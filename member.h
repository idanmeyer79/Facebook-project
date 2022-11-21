#ifndef __MEMBER_H__
#define __MEMBER_H__
#include "status.h"
#include "Date.h"
#include "page.h"

static int NumOfMembers = 0;

class Member
{
private:
	char* memberName;
	Date dateOfBirth;
	Member** memberFriends;
	Status** memberStatuses;
	FanPage** memberFanPages;
	int numOfStatusesOfMember = 0;
	int numOfFriendsOfMember = 0;
	int numOfFanPagesOfMember = 0;

public:
	Member(char* name, Date dateOfBirth);
	void setName(char* Name);
	char* getName();
	void setDate(Date date);
	Date getDate();
	void addFriend(Member* member1, Member* member2);
	Member** membersRealloc(Member** arrOfPFriends, int numOfNewFriends);
	void removeFriend(Member* member1, Member* member2);
	void showFriends();
	void addStatus();
	Status** statusRealloc(Status** arrOfPStatuses, int numOfStatusesOfMember);
	void showFanPage();
	void showMyStatuses();
	void addFanPage(FanPage* fanPage, Member* member1);
	FanPage** fanPageRealloc(FanPage** arrOfPFanPages, int memberFanPages);
	Member* findMember(char* name);
	void Show10LastStatuses(Member* member);
};

#endif // !__MEMBER_H__
