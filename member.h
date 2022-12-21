#ifndef __MEMBER_H__
#define __MEMBER_H__
#include "Date.h"
#include "FanPage.h"
#include"status.h"
#include <iostream>
#include<vector>
#include<list>
#pragma warning(disable: 4996)

class PagesArray;
class MembersArray;
class FanPage;

class Member
{
private:
	std::string memberName;
	Date dateOfBirth;
	//MembersArray* memberFriends;
	//StatusesArray memberStatuses;
	std::vector<Status> memberStatuses;
	std::list<FanPage*> memberFanPages;
	std::list<Member*> memberFriends;
	//PagesArray* memberFanPages;

public:

	Member(const std::string name, const Date& dateOfBirth) noexcept(false);
	~Member();
	std::list<Member*> getMembersArray()  { return memberFriends; }
	std::vector<Status> getStatusesArray() { return memberStatuses; }
	std::list<FanPage*> getPagesArray()   { return memberFanPages; }
	std::string getName() const;
	const Date getDate()const;
	const int getNumOfFriends() const ;
	bool setName(const std::string name);
	void setBirthDay(Date& date);
	void followPage(FanPage& fanPage);
	void showFriends() const;
	void showFanPages() const;
	void showMyStatuses() const;
	void Show10MyFriendsLastStatuses()const;
	void addFriend(Member& member);
	void addStatus();
	void addStatus(const std::string text);
	void addStatus(Status& status);
	void unFriend(Member& member);
	void printMyLast10Statuses()const;
	void disConnectPage(FanPage& page);
	bool checkFriendship(const std::string name);
	bool checkIfAlreadyFolowing(const std::string name);
	//From pages Array
	int getNumOfPages() { return memberFanPages.size(); }
	void addPage(FanPage& p);
	FanPage* addPage(const std::string name);
	void printAllPages() const;
	FanPage* findPage(std::string name);
	bool checkIfNameExist(const std::string name) const;
	void deletePage(FanPage& page);
	//from members array
	int getNumOfMembers() { return memberFriends.size(); }
	Member* getMember(const std::string name);
	void printAllMembers() const;
	void showLast10StatusesOfEach() const;
	void deleteMember(Member& member);
	void addMember(Member& p);
	Member* addMember(const std::string name, const Date& dateOfBirth);
	//from statuses array
	std::vector<Status> getStatusArray() { return memberStatuses; }
	void addStatusToArray(Status& s);
	void printAllStatuses() const;
	void print10() const;

	Member& operator+=(Member& other);
	Member& operator+=(FanPage& other);
	bool operator>(FanPage& other);
	bool operator>(Member& other);
};

#endif // !__MEMBER_H__
