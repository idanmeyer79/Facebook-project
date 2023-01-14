#include "Member.h"
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#pragma warning(disable: 4996)
using namespace std;

Member::~Member()
{
	freeStatuses();
}

Member::Member(const string name, const Date& date) : dateOfBirth(date)
{
	memberName = name;
}

Member::Member(const Member& other):dateOfBirth(other.dateOfBirth)
{
	for (const Status* status : other.memberStatuses)
	{
		string type = typeid(*status).name() + SKIP_CLASS;
		if (type == "Status")
		{
			Status* newStatus = new Status(*status);
			memberStatuses.push_back(newStatus);
		}
		else if (type == "StatusWithPhoto")
		{
			Status* newStatus = new StatusWithPhoto(*((StatusWithPhoto*)(status)));
			memberStatuses.push_back(newStatus);
		}
		else
		{
			Status* newStatus = new StatusWithVideo(*((StatusWithVideo*)(status)));
			memberStatuses.push_back(newStatus);
		}
	}
	memberFanPages = other.memberFanPages;
	memberFriends = other.memberFriends;
	memberName = other.memberName;
}

Member::Member(Member&& other):dateOfBirth(other.dateOfBirth)
{
	memberFanPages = move(other.memberFanPages);
	memberFriends = move(other.memberFriends);
	memberName = move(other.memberName);
	memberStatuses = move(other.memberStatuses);
}

Member& Member::operator=(Member&& other)
{
	if (this != &other)
	{
		dateOfBirth = move(other.dateOfBirth);
		memberFanPages = move(other.memberFanPages);
		memberFriends = move(other.memberFriends);
		memberName = move(other.memberName);
		memberStatuses = move(other.memberStatuses);
	}
	return *this;
}

Member& Member::operator=(const Member& other)
{
	if (this != &other)
	{
		dateOfBirth = other.dateOfBirth;
		memberFanPages = other.memberFanPages;
		memberFriends = other.memberFriends;
		memberName = other.memberName;
		memberStatuses = other.memberStatuses;
	}
	return *this;
}

Member::Member(std::ifstream& file):dateOfBirth(file)
{
	// read memberName from file
	std::getline(file, memberName);
	// read memberStatuses from file
	int statusesCount;
	string type;
	Status* status;
	file >> statusesCount;
	file.ignore();
	for (int i = 0; i < statusesCount; ++i)
	{
		getline(file, type);
		if (type == "Status")
			status = new Status(file);
		else if (type == "StatusWithPhoto")
			status = new StatusWithPhoto(file);
		else
			status = new StatusWithVideo(file);
		memberStatuses.push_back(status);
	}
}

bool Member :: setName(const string name)
{
	if (checkIfMemberNameExist(name))
		return false;
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

void Member::saveToFile(std::ofstream& outFile) const
{
	//Save the Date of birth
	outFile << dateOfBirth << '\n';
	// Save the member name
	outFile << memberName << '\n';
	// Save the statuses
	outFile << memberStatuses.size() << '\n';
	for (const Status* status : memberStatuses)
		status->saveToFile(outFile);
}

const Date Member::getDate() const
{ 
	return dateOfBirth; 
}

void Member::addFriend(Member& member)
{
	memberFriends.push_back(&member);
	member.memberFriends.push_back(this);
}

Member& Member:: operator+=(Member& other)
{
	addFriend(other);
	return *this;
}

Member& Member:: operator+=(FanPage& other)
{
	this->followPage(other);
	return *this;
}

void Member::disConnectPage(FanPage& page)
{
	deletePage(page);
	page.removeFan(*this);
}

void Member::unFriend(Member& member)
{
	deleteMember(member);
	member.deleteMember(*this);
}

void Member::followPage(FanPage& fanPage)
{
	addPage(fanPage);
	fanPage.addFan(*this);
}

void Member::showFriends()  const
{
	cout << memberName << "'s friends are:" << endl;
	printAllMembers();
}

void Member::showFanPages() const
{
	cout << memberName << "'s fan pages are:" << endl;
	printAllPages();
}

void Member::addStatus(const string text)
{
	Status *status = new Status(text);
	addStatus(status);
}

void Member::addStatus(Status* status)
{
	memberStatuses.push_back(status);
}

void Member::showMyStatuses() const
{
	cout << memberName << " ";
	printAllStatuses();
}
 
bool Member::checkFriendship(const string name)
{
	return getMember(name);
}

bool Member::checkIfAlreadyFolowing(const string name)
{
	return findPage(name);
}

void Member::printMyLast10Statuses() const
{
	cout << memberName << " statuses:" << endl;
	print10();
}

const int Member::getNumOfFriends()  const
{ 
	return memberFriends.size();
}

bool Member:: operator>(Member& other)
{
	return getNumOfFriends() > other.getNumOfFriends() ? true : false;
}

bool Member:: operator>(FanPage& other) 
{
	return getNumOfFriends() > other.getNumOfFans() ? true : false;
}

//from pages array
void Member::deletePage(FanPage& page)
{
	list<FanPage*>::iterator itr = memberFanPages.begin();
	list<FanPage*>::iterator itrEnd = memberFanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == page.getName())
		{
			memberFanPages.erase(itr);
			return;
		}
	}
}

void Member::addPage(FanPage& p)
{
	memberFanPages.push_back(&p);
}

void Member::printAllPages() const
{
	list<FanPage*>::const_iterator itr = memberFanPages.begin();
	list<FanPage*>::const_iterator itrEnd = memberFanPages.end();
	int i = 0;
	int numOfPages = memberFanPages.size();

	if (numOfPages == 0)
	{
		cout << "None" << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
		cout << "#" << ++i << " " << (*itr)->getName() << endl;
}

FanPage* Member::findPage(string name)
{
	FanPage* theFoundPage = nullptr;
	list<FanPage*>::iterator itr = memberFanPages.begin();
	list<FanPage*>::iterator itrEnd = memberFanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name)
		{
			theFoundPage = (*itr);
			return theFoundPage;
		}
	}
	return theFoundPage;
}

bool Member::checkIfMemberNameExist(const string& name) const
{
	list<Member*>::const_iterator itr = memberFriends.begin();
	list<Member*>::const_iterator itrEnd = memberFriends.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name)
			return true;
	}
	return false;
}

void Member::deleteMember(Member& member)
{
	list<Member*>::iterator itr = memberFriends.begin();
	list<Member*>::iterator itrEnd = memberFriends.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == member.getName())
		{
			memberFriends.erase(itr);
			return;
		}
	}
}

void Member::printAllMembers() const
{
	list<Member*>::const_iterator itr = memberFriends.begin();
	list<Member*>::const_iterator itrEnd = memberFriends.end();
	int numOfMembers = memberFriends.size();
	int i = 0;

	if (numOfMembers == 0)
	{
		cout << "None" << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
		cout << "#" << ++i << " " << (*itr)->getName() << endl;
}

Member* Member::getMember(const string name) 
{
	list<Member*>::iterator itr = memberFriends.begin();
	list<Member*>::iterator itrEnd = memberFriends.end();

	Member* theFoundMember = nullptr;

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == name)
		{
			theFoundMember = (*itr);
			return theFoundMember;
		}
	}
	return theFoundMember;
}

void Member::showLast10StatusesOfEach() const
{
	list<Member*>::const_iterator itr = memberFriends.begin();
	list<Member*>::const_iterator itrEnd = memberFriends.end();

	for (; itr != itrEnd; ++itr)
		(*itr)->printMyLast10Statuses();
}

void Member::printAllStatuses() const
{
	vector<Status*>::const_iterator itr = memberStatuses.begin();
	vector<Status*>::const_iterator itrEnd = memberStatuses.end();

	int i = 0;
	cout << "All the statuses:" << endl;
	if (memberStatuses.size() == 0)
		cout << "None" << endl;
	else
	{
		for (; itr != itrEnd; ++itr)
		{
			cout << "# " << ++i << " ";
			(*itr)->printStatus();
		}
	}
}

void Member::print10() const
{
	vector<Status*>::const_reverse_iterator  rit = memberStatuses.rbegin();
	vector<Status*>::const_reverse_iterator ritrEnd = memberStatuses.rend();
	int size = memberStatuses.size();
	int currMemberNumOfStatuses = min(size, 10);
	for (int i=0; i< currMemberNumOfStatuses; ++rit,i++)
		(*rit)->printStatus();
	cout << endl;
}

void Member::freeStatuses()
{
	for (auto& status : memberStatuses)
	{
		delete status;
	}
	memberStatuses.clear();
}