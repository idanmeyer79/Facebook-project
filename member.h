#ifndef __MEMBER_H__
#define __MEMBER_H__
#include"member.h"
#include"status.h"
#include"Date.h"

static int NumOfMembers = 0;

class Member
{
public: //for test
	char name[20];
	Date dateOfBirth;
	Member* friends;
	status* statuses;
	int numOfStatuses = 0;
	int numOfFriends = 0;


public:
	Member() {}
	void setName(const char* username) { strcpy(name, username); }
	char* getName() { return name; }
	void addFriend(Member Friend);
	void printFriends();
	void removeFriend(Member Friend);
	void printAllStatuses();
};

#endif // !__MEMBER_H__
