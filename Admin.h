#ifndef __ADMIN_H__
#define __ADMIN_H__
#include"PagesArray.h"
#include "MembersArray.h"
#include "Date.h"
#include"Status.h"
#include "FanPage.h"
#include "Member.h"
#include <iostream>
#pragma warning(disable: 4996)

class Admin
{
private:
	

public:
	PagesArray fanPages;
	MembersArray users;
	//צריך לבדוק
	//AllPages getFanPages()  {return fanPages ;}
	//AllMembers getusers() { return users; }
	void printMenu();
	void menu();
	void createFanPage();
	Member* getDetailsForMember();
	FanPage* getDetailsForPage();
	void createMember();
	void addStatusToFanPageOrMember();
	void showAllStatusesOfMemberOrFanPage();
	void makeFriendship();
	void makeFriendship(Member member1, Member member2);
	void ConnectFanToPage(Member member, FanPage page);
	void printAllFriends();
};

#endif // !__ADMIN_H__