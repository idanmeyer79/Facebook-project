#include "FanPage.h"
using namespace std;

FanPage::FanPage(const char* name) 
{
	pageName = new char[strlen(name) + 1];
	strcpy(pageName, name);
	fans = new MembersArray;
}

FanPage:: ~FanPage()
{
	delete[]pageName;
}

const char* FanPage::getName() const
{ 
	return pageName; 
}

bool FanPage::setName(const char* name) 
{
	if (strlen(name) > LEN_OF_NAME)
		return false;

	strcpy(this->pageName, name);
	return true;
}

void FanPage::addFan(Member& fan)
{
	fans->addMember(fan);
}

const int FanPage::getNumOfFans() const
{
	return fans->getNumOfMembers();
}

void FanPage::removeFan(Member& fan)
{
	fans->deleteMember(fan);
}

void FanPage::printFans() const
{
	fans->printAllMembers();
}

void FanPage::showMyStatuses()
{
	cout << pageName << " ";
	statuses.printAllStatuses();
}

void FanPage::addStatus()
{
	char text[LEN_OF_STATUS];
	cout << "Please enter new status: " << endl;
	cin.getline(text, LEN_OF_STATUS);
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