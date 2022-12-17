#include "FanPage.h"
#include<string>
using namespace std;

FanPage::FanPage(const string name) 
{
	//pageName = new char[strlen(name) + 1];
	pageName= name;
	fans = new MembersArray;
}

FanPage:: ~FanPage()
{
	delete[]fans;
}

string FanPage::getName()
{ 
	return pageName; 
}

bool FanPage::setName(const string name) 
{
	pageName = name;
	return true;
}

void FanPage::addFan(Member& fan)
{
	fans->addMember(fan);
}

int FanPage::getNumOfFans()
{
	return fans->getNumOfMembers();
}

void FanPage::removeFan(Member& fan)
{
	fans->deleteMember(fan);
}

void FanPage::printFans()
{
	fans->printAllMembers();
}

void FanPage::showMyStatuses()
{
	statuses.printAllStatuses();
}

void FanPage::addStatus()
{
	string text;
	cout << "Please enter new status: " << endl;
	getline(std::cin, text);
	Status* status = new Status(text);
	statuses.addStatusToArray(*status);
}

void FanPage::addStatus(Status& s)
{
	statuses.addStatusToArray(s);
}

void FanPage::addStatus(const string txt)
{
	Status* status = new Status(txt);
	statuses.addStatusToArray(*status);
}

FanPage& FanPage:: operator+=(Member& other)
{
	other.followPage(*this);
	return *this;
}

bool FanPage:: operator>(Member& other)
{
	return getNumOfFans() > other.getNumOfFriends() ? true: false;
}

bool FanPage:: operator>(FanPage& other) 
{
	return getNumOfFans() > other.getNumOfFans()? true : false;
}