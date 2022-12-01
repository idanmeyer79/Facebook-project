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
	void printMenu();
	void menu();
	void createFanPage();
	Member* getDetailsForMember();
	FanPage* getDetailsForPage();
	void createMember();
	void addStatusToFanPageOrMember();
	void showAllStatusesOfMemberOrFanPage();
	void makeFriendship();
	void makeFriendship(Member member1, Member member2); // by ref
	void ConnectFanToPage(Member member, FanPage page); //by ref
	void ConnectFanToPage();
	void printAllFriendsOfMemberOrFanPage();
	void showLast10StatusesOfFriendsOfMember();
	void unFriendship();
	void disConnectFanAndPage();
};

#endif // !__ADMIN_H__