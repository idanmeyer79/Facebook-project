#ifndef __ADMIN_H__
#define __ADMIN_H__
#include "Date.h"
#include"Status.h"
#include "FanPage.h"
#include "Member.h"
#include <iostream>
#include <vector>
#include <list>
#pragma warning(disable: 4996)
#pragma warning(disable: 4267)

class FanPage;
class Member;

class Admin
{
private:
	std::list<FanPage> fanPages;
	std::list<Member>  users;
	
public:
	const std::list<Member>& getMembersArray();
	const std::list<Member> getUsers() const              { return users; }
    const std::list<FanPage>& getPagesArray();
	void setPagesArray(std::list<FanPage> newFanPages)  { fanPages = newFanPages; }
	void setMembersArray(std::list<Member> newUsers)    { users = newUsers;       }
	void printAcounts() const;
	void addPageToFacebook(const FanPage& page);
	void addUserToFacebook(const Member& member);
	void makeFriendship(Member& member1, Member& member2);
	void ConnectFanToPage(Member& member, FanPage& page);
	void unFriendship(Member& member1, Member& member2);
	void disConnectFanAndPage(Member& member, FanPage& page);
	void addStatusToPage(FanPage* page, const Status& status);
	void addStatusToMember(Member* member, const Status& status);
	int getNumOfMembers() { return users.size(); }
	Member* getMember(const std::string name);
	bool checkIfUserNameExist(const std::string name) const;
	bool checkIfPageNameExist(const std::string name) const;
	void printAllMembers() const;
	void showLast10StatusesOfEach() const;
	void deleteMember(Member& member);
	int getNumOfPages() { return fanPages.size(); }
	void printAllPages() const;
	void deletePage(FanPage& page);

	friend class FacebookIO;
};

#endif // !__ADMIN_H__