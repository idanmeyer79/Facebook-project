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

char* Member :: getName()
{
	return memberName;
}

void Member ::setBirthDay(Date& date)
{
	dateOfBirth = date;
}

Date Member::getDate()
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
	cout << endl << memberName << " is no longer follows " << page.getName() << endl;
}

void Member::unFriend(Member& member)
{
	memberFriends->deleteMember(member);
	member.memberFriends->deleteMember(*this);
	cout << endl <<member.getName() << " and " << memberName << " are no longer friends :(" << endl;
}

void Member::followPage(FanPage& fanPage)
{
	memberFanPages->addPage(fanPage);
	fanPage.addFan(*this);
}

void Member::showFriends() 
{
	memberFriends->printAllMembers();
}

void Member::showFanPages()
{
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

void Member::showMyStatuses()
{
	memberStatuses.printAllStatuses();
}
 
bool Member::checkFriendship(const char* name)
{
	return memberFriends->getMember(name);
}

bool Member::checkIfAlreadyFolowing(const char* name)
{
	return memberFanPages->findPage(name);
}

void Member::Show10MyFriendsLastStatuses()
{
	memberFriends->showLast10StatusesOfEach();
}

void Member::printMyLast10Statuses()
{
	cout << memberName << " statuses:" << endl;
	memberStatuses.print10();
}

int Member::getNumOfFriends() 
{ 
	return memberFriends->getNumOfMembers(); 
}
