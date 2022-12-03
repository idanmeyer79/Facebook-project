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
public:
	static constexpr int LEN_OF_NAME = 20;

private:
	PagesArray fanPages;
	MembersArray users;
	

public:
	Admin() = default;
	Admin(Admin& other) = delete;
	void printMenu() ;
	void menu();
	void createFanPage();
	Member* getDetailsForMember();
	FanPage* getDetailsForPage();
	PagesArray& getPagesArray();
	void createMember();
	void addStatusToFanPageOrMember();
	void showAllStatusesOfMemberOrFanPage();
	void makeFriendship();
	void makeFriendship(Member& member1, Member& member2) ;
	void ConnectFanToPage(Member& member, FanPage& page);
	void ConnectFanToPage();
	void printAllFriendsOfMemberOrFanPage();
	void showLast10StatusesOfFriendsOfMember();
	void unFriendship();
	void disConnectFanAndPage();
	void hardCodedData();
};

#endif // !__ADMIN_H__