#ifndef __ADMIN_H__
#define __ADMIN_H__
#include"PagesArray.h"
#include "MembersArray.h"
#include "Date.h"
#include"Status.h"
#include "FanPage.h"
#include "Member.h"
#include <iostream>
#include <vector>
#pragma warning(disable: 4996)

class FanPage;
class Member;

class Admin
{
private:
	std::vector<FanPage> fanPages;
	std::vector<Member>users;
	
public:
	Admin() = default;
	const std::vector<Member>& getMembersArray();
	Member* getDetailsForMember() const;
	FanPage* getDetailsForPage() const;
    const std::vector<FanPage>& getPagesArray();
	void setPagesArray(std::vector<FanPage> newFanPages)  { fanPages = newFanPages; }
	void setMembersArray(std::vector<Member> newUsers)    { users = newUsers;       }
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
	//from members array
	int getNumOfMembers() { return users.size(); }
	Member* getMember(const std::string name);
	bool checkIfNameExist(const std::string name) const;
	void printAllMembers() const;
	void showLast10StatusesOfEach() const;
	void deleteMember(Member& member);
	void addMember(Member& p);
	Member* addMember(const std::string name, const Date& dateOfBirth);
	//from pages array
	int getNumOfPages() { return fanPages.size(); }
	void addPage(FanPage& p);
	FanPage* addPage(const std::string name);
	void printAllPages() const;
	FanPage* findPage(std::string name);
	void deletePage(FanPage& page);
};

#endif // !__ADMIN_H__