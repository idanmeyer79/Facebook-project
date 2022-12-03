#include "FanPage.h"
using namespace std;

FanPage::FanPage(const char* name) 
{
	pageName = new char[strlen(name) + 1];
	strcpy(pageName, name);
	fans = new MembersArray;
}

char* FanPage::getName()
{ 
	return pageName; 
}

bool FanPage::setName(const char* name) 
{
	strcpy(this->pageName, name);
	return true;
}

void FanPage::addFan(Member& fan)
{
	fans->addMember(fan);
}

int FanPage::getNumOfFans()
{
	return fans->getNumOfUsres(); 
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
	char text[100];
	cout << "Please enter new status: " << endl;
	cin.getline(text, 100);
	Status* status = new Status(text);
	statuses.addStatusToArray(*status);
}

void FanPage::addStatus(Status& s)
{
	statuses.addStatusToArray(s);
}

void FanPage::addStatus(const char* txt)
{
	Status* status = new Status(txt);
	statuses.addStatusToArray(*status);
}