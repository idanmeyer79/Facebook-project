#include "FanPage.h"
using namespace std;

FanPage::FanPage(const string name) 
{
	//pageName = new char[strlen(name) + 1];
	pageName= name;
	fans = new MembersArray;
}

//FanPage:: ~FanPage()
//{
//	delete[]pageName;
//}

string FanPage::getName()
{ 
	return pageName; 
}

bool FanPage::setName(const string name) 
{
	//if (strlen(name) > LEN_OF_NAME)
	//	return false;
	pageName = name;
	//strcpy(this->pageName, name);
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
	cin >> text;
	//cin.getline(text, LEN_OF_STATUS);
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