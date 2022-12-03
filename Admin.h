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
	Admin(const Admin& other) = delete;
	const MembersArray& getMembersArray() const;
	Member* getDetailsForMember() const;
	FanPage* getDetailsForPage() const;
    const PagesArray& getPagesArray() const;
	void setPagesArray(PagesArray newFanPages)  { fanPages = newFanPages; }
	void setMembersArray(MembersArray newUsers) { users = newUsers;       }
	void printMenu();
	void printAcounts() const;
	void printAllFriendsOfMemberOrFanPage();
	void menu();
	void createFanPage();
	void createMember();
	void addStatusToFanPageOrMember();
	void showAllStatusesOfMemberOrFanPage();
	void makeFriendship();
	void makeFriendship(Member& member1, Member& member2);
	void ConnectFanToPage(Member& member, FanPage& page);
	void ConnectFanToPage();
	void showLast10StatusesOfFriendsOfMember();
	void unFriendship();
	void disConnectFanAndPage();
	void hardCodedData();
	Member* getMemberToAction();
	FanPage* getFanPageToAction();
};

#endif // !__ADMIN_H__