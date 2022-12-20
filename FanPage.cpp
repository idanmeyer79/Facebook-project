#include "FanPage.h"
#include<string>
using namespace std;

FanPage::FanPage(const string name) 
{
	if (checkIfNameExist(name))
	{
		throw name;
	}
	//pageName = new char[strlen(name) + 1];
	pageName= name;
}

//FanPage:: ~FanPage()
//{
//	delete[]fans;
//}

string FanPage::getName() const
{ 
	return pageName; 
}

bool FanPage::setName(const string name) 
{
	if (checkIfNameExist(name))
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

const int FanPage::getNumOfFans() const
{
	return fans.size();
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

void FanPage::addStatus()//this needs to go
{
	string text;
	cout << "Please enter new status: " << endl;
	getline(std::cin, text);
	Status* status = new Status(text);
	addStatusToArray(*status);
}

void FanPage::addStatus(Status& s)
{
	addStatusToArray(s);
}

void FanPage::addStatus(const string txt)
{
	Status* status = new Status(txt);
	addStatusToArray(*status);
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

//from status array
void FanPage::addStatusToArray(Status& s)
{
	//if (numOfMaxStatuses == numOfStatuses) {
	//	numOfMaxStatuses = numOfMaxStatuses * 2;
	//	Status** tmp = new Status * [numOfMaxStatuses];
	//	for (int i = 0; i < numOfStatuses; i++)
	//		tmp[i] = statusArray[i];
	//	delete[] statusArray;
	//	statusArray = tmp;
	//}
	statuses.push_back(s);
	//statusArray[numOfStatuses] = &s;
	//numOfStatuses++;
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

//from members array
bool FanPage::checkIfNameExist(const string name) const
{
	vector<Member>::const_iterator itr = fans.begin();
	vector<Member>::const_iterator itrEnd = fans.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == name)//!strcmp(name, membersArray[i]->getName()))
		{
			cout << "\033[1;31mName already taken, please enter another name.\033[0m" << endl;
			return true;
		}
	}
	return false;
}

void FanPage::addMember(Member& m)
{
	//if (numOfMaxMembers == numOfMembers) {
	//	numOfMaxMembers = numOfMaxMembers * 2;
	//	Member** tmp = new Member * [numOfMaxMembers];
	//	for (int i = 0; i < numOfMembers; i++)
	//		tmp[i] = membersArray[i];
	//	membersArray = tmp;
	//	tmp = nullptr;
	//	delete[] tmp;
	//}
	fans.push_back(m);
	//membersArray[numOfMembers] = &m;
	//numOfMembers++;
}

void FanPage::deleteMember(Member& member)
{
	vector<Member>::iterator itr = fans.begin();
	vector<Member>::iterator itrEnd = fans.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == member.getName())
		{
			fans.erase(itr);
			return;
		}
	}
}

void FanPage::printAllMembers() const
{

	vector<Member>::const_iterator itr = fans.begin();
	vector<Member>::const_iterator itrEnd = fans.end();
	int numOfMembers = fans.size();
	int i = 0;

	if (numOfMembers == 0)
	{
		cout << "None" << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
	{
		cout << "#" << ++i << " " << (*itr).getName() << endl;
	}
}

