#include "FanPage.h"
#include <fstream>
#include<string>
using namespace std;

FanPage::FanPage(const string name) 
{
	pageName= name;
}

string FanPage::getName() const
{ 
	return pageName; 
}

bool FanPage::setName(const string name) 
{
	if (checkIfFanExist(name))
	{
		return false;
	}
	pageName = name;
	return true;
}

void FanPage::addFan(Member& fan)
{
	addMember(fan);
}

void FanPage::removeFan(Member& fan)
{
	deleteMember(fan);
}

void FanPage::printFans() const
{
	printAllMembers();
}

void FanPage::showMyStatuses()
{
	cout << pageName << " "<<endl;
	printAllStatuses();
}

void FanPage::addStatus(const string txt)
{
	Status *status = new Status(txt);
	addStatusToArray(status);
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

void FanPage::saveToFile(std::ofstream& outFile) const
{
	outFile << pageName << '\n';
	outFile << statuses.size() << '\n';
	for (const Status* status : statuses)
		status->saveToFile(outFile);
}

bool FanPage:: operator>(FanPage& other) 
{
	return getNumOfFans() > other.getNumOfFans()? true : false;
}

void FanPage::addStatusToArray(Status* s)
{
	statuses.push_back(s);
}

void FanPage::printAllStatuses() const
{
	vector<Status*>::const_iterator itr = statuses.begin();
	vector<Status*>::const_iterator itrEnd = statuses.end();

	int i = 0;
	cout << "All the statuses:" << endl;
	for (; itr != itrEnd; ++itr)
	{
		cout << "# " << ++i << " ";
		(*itr)->printStatus();
	}
}

bool FanPage::checkIfFanExist(const string& name) const
{
	list<Member*>::const_iterator itr = fans.begin();
	list<Member*>::const_iterator itrEnd = fans.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name)
		{
			cout << "\033[1;31mName already taken, please enter another name.\033[0m" << endl;
			return true;
		}
	}
	return false;
}

void FanPage::addMember(Member& m)
{
	fans.push_back(&m);
}

void FanPage::deleteMember(Member& member)
{
	list<Member*>::iterator itr = fans.begin();
	list<Member*>::iterator itrEnd = fans.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == member.getName())
		{
			fans.erase(itr);
			return;
		}
	}
}

void FanPage::printAllMembers() const
{
	list<Member*>::const_iterator itr = fans.begin();
	list<Member*>::const_iterator itrEnd = fans.end();
	int numOfMembers = fans.size();
	int i = 0;

	if (numOfMembers == 0)
	{
		cout << "None" << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
		cout << "#" << ++i << " " << (*itr)->getName() << endl;
}

FanPage::FanPage(ifstream& file)
{
	getline(file, pageName);
	int statusesCount;
	string type;
	Status* status;
	file >> statusesCount;
	file.ignore();
	for (int i = 0; i < statusesCount; ++i) {
		getline(file,type);
		if (type=="Status")
			status = new Status(file);
		else if(type == "StatusWithPhoto")
			status = new StatusWithPhoto(file);
		else
			status = new StatusWithVideo(file);
		statuses.push_back(status);
	}
}

list<Member*> FanPage::getFans() const
{ 
	return fans;
}
