#include "FanPage.h"
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
	Status status(txt);
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

bool FanPage:: operator>(FanPage& other) 
{
	return getNumOfFans() > other.getNumOfFans()? true : false;
}

void FanPage::addStatusToArray(const Status& s)
{
	statuses.push_back(s);
}

void FanPage::printAllStatuses() const
{
	vector<Status>::const_iterator itr = statuses.begin();
	vector<Status>::const_iterator itrEnd = statuses.end();

	int i = 0;
	cout << "All the statuses:" << endl;
	for (; itr != itrEnd; ++itr)
	{
		cout << "# " << ++i << " ";
		(*itr).printStatus();
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
	{
		cout << "#" << ++i << " " << (*itr)->getName() << endl;
	}
}