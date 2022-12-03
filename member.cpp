#include "Member.h"
#include <cmath>
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

Member::Member(const char* name, const Date& date) : dateOfBirth(date)
{
	memberName = new char[strlen(name) + 1];
	strcpy(memberName, name);
	memberFriends = new MembersArray;
	memberFanPages = new PagesArray;
}

Member::~Member()
{
	delete[]memberName;
}

bool Member :: setName(const char* name)
{
	if (strlen(name) > LEN_OF_NAME)
		return false;

	strcpy(memberName , name);
	return true;
}

const char* Member :: getName() const
{
	return memberName;
}

void Member ::setBirthDay(Date& date)
{
	dateOfBirth = date;
}

const Date Member::getDate() const
{ 
	return dateOfBirth; 
}

void Member::addFriend(Member& member)
{
	memberFriends->addMember(member);
	member.memberFriends->addMember(*this);
}

void Member::disConnectPage(FanPage& page)
{
	memberFanPages->deletePage(page);
	page.removeFan(*this);
}

void Member::unFriend(Member& member)
{
	memberFriends->deleteMember(member);
	member.memberFriends->deleteMember(*this);
}

void Member::followPage(FanPage& fanPage)
{
	memberFanPages->addPage(fanPage);
	fanPage.addFan(*this);
}

void Member::showFriends()  const
{
	cout << memberName << "'s friends are:" << endl;
	memberFriends->printAllMembers();
}

void Member::showFanPages() const
{
	cout << memberName << "'s fan pages are:" << endl;
	memberFanPages->printAllPages();
}

void Member :: addStatus() 
{
	char text[LEN_OF_STATUS];
	cout << "Please enter new status: " << endl;
	cin.getline(text,LEN_OF_STATUS);
	Status* status = new Status(text);
	memberStatuses.addStatusToArray(*status);
}

void Member::addStatus(const char* text)
{
	Status* status = new Status(text);
	memberStatuses.addStatusToArray(*status);
}

void Member::addStatus(Status& status)
{
	memberStatuses.addStatusToArray(status);
}

void Member::showMyStatuses() const
{
	cout << memberName << " ";
	memberStatuses.printAllStatuses();
}
 
bool Member::checkFriendship(const char* name) const
{
	return memberFriends->getMember(name);
}

bool Member::checkIfAlreadyFolowing(const char* name) const
{
	return memberFanPages->findPage(name);
}

void Member::Show10MyFriendsLastStatuses() const
{
	memberFriends->showLast10StatusesOfEach();
}

void Member::printMyLast10Statuses() const
{
	cout << memberName << " statuses:" << endl;
	memberStatuses.print10();
}

const int Member::getNumOfFriends()  const
{ 
	return memberFriends->getNumOfMembers(); 
}
