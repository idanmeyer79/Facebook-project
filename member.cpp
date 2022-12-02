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
	//שיש שדות לא מאותחלים פה
}

void Member :: setName(const char* Name)
{
	strcpy(memberName , Name);
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
	char text[100];
	cout << "Please enter new status: " << endl;
	cin.getline(text,100);
	Status* status = new Status(text);
	memberStatuses.addStatusToArray(*status);
}

void Member:: addStatus(Status& status)
{
	memberStatuses.addStatusToArray(status);
}

Status& Member::addStatus(const char* txt)
{
	Status* status = new Status(txt);
	memberStatuses.addStatusToArray(*status);
	return *status;
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
