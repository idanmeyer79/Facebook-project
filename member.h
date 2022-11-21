#ifndef __MEMBER_H__
#define __MEMBER_H__
#include"member.h"
#include"status.h"
#include"Date.h"

static int NumOfMembers = 0;

class Member
{
private:
	char* name;
	Date dateOfBirth;
	Member* friends;
	status* statuses;
	int numOfStatuses = 0;
	int numOfFriends = 0;


public:
	Member(char* name, Date dateOfBirth);
	bool setName();
	char* getName() { return name; }
	void addFriend(Member Friend);
	void printFriends();
	void removeFriend(Member Friend);
	void printAllStatuses();
};

#endif // !__MEMBER_H__
