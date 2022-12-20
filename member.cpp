#include "Member.h"
#include <cmath>
#include <iostream>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

Member::Member(const string name, const Date& date) : dateOfBirth(date)
{
	memberName = name;
	memberFriends = new MembersArray;
	memberFanPages = new PagesArray;
}

Member::~Member()
{
	delete []memberFriends;
	delete []memberFanPages;
	//memberStatuses.free();
}

bool Member :: setName(const string name)
{
	memberName = name;
	return true;
}

string Member :: getName() const
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

Member& Member:: operator+=(Member& other){
	addFriend(other);
	return *this;
}

Member& Member:: operator+=(FanPage& other){
	this->followPage(other);
	return *this;
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
	string text;
	cout << "Please enter new status: " << endl;
	getline(std::cin, text);
	Status* status = new Status(text);
	memberStatuses.addStatusToArray(*status);
}

void Member::addStatus(const string text)
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
 
bool Member::checkFriendship(const string name)
{
	return memberFriends->getMember(name);
}

bool Member::checkIfAlreadyFolowing(const string name)
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

bool Member:: operator>(Member& other)
{
	return getNumOfFriends() > other.getNumOfFriends() ? true : false;
}

bool Member:: operator>(FanPage& other) 
{
	return getNumOfFriends() > other.getNumOfFans() ? true : false;
}