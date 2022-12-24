#include "Admin.h"
#include <string>
#include<vector>
using namespace std;
#pragma warning(disable: 4267)
#pragma warning(disable: 6031)

const list<FanPage>& Admin:: getPagesArray()
{
	return fanPages;
}

const list<Member>& Admin::getMembersArray()
{
	return users;
}

void Admin::printAcounts() const
{
	cout << "All the members:" << endl;
	printAllMembers();
	cout << "All the pages:" << endl;
	printAllPages();
}

void Admin::addUserToFacebook(const Member& member)
{
	users.push_back(member);
}

void Admin::addPageToFacebook(const FanPage& page)
{
	fanPages.push_back(page);
}

void Admin::addStatusToMember(Member* member, const Status& status)
{
	member->addStatusToArray(status);
}

void Admin::addStatusToPage(FanPage* page, const Status& status)
{
	page->addStatusToArray(status);
}

void Admin::makeFriendship(Member& member1, Member& member2)
{
	member1.addFriend(member2);
}

void Admin::unFriendship(Member& member1, Member& member2)
{
	member1.unFriend(member2);
}

void Admin::disConnectFanAndPage(Member& member,FanPage& page)
{
	member.disConnectPage(page);
}

void Admin::ConnectFanToPage(Member& member, FanPage& page) 
{
	member.followPage(page);
}

bool Admin::checkIfUserNameExist(const string name) const
{
	list<Member>::const_iterator itr = users.begin();
	list<Member>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == name)
		{
			return true;
		}
	}
	return false;
}

bool Admin::checkIfPageNameExist(const string name) const
{
	list<FanPage>::const_iterator itr = fanPages.begin();
	list<FanPage>::const_iterator itrEnd = fanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == name)
		{
			return true;
		}
	}
	return false;
}

void Admin::deleteMember(Member& member)
{
	list<Member>::iterator itr = users.begin();
	list<Member>::iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == member.getName())
		{
			users.erase(itr);
			return;
		}
	}
}

void Admin::printAllMembers() const
{
	list<Member>::const_iterator itr = users.begin();
	list<Member>::const_iterator itrEnd = users.end();
	int numOfMembers = users.size();
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

Member* Admin::getMember(const string name) 
{
	list<Member>::iterator itr = users.begin();
	list<Member>::iterator itrEnd = users.end();

	Member* theFoundMember = nullptr;

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == name)
		{
			theFoundMember = &(*itr);
			return theFoundMember;
		}
	}
	return theFoundMember;
}

void Admin::showLast10StatusesOfEach() const
{
	list<Member>::const_iterator itr = users.begin();
	list<Member>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr).printMyLast10Statuses();
	}
}

void Admin::deletePage(FanPage& page)
{
	list<FanPage>::iterator itr = fanPages.begin();
	list<FanPage>::iterator itrEnd = fanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == page.getName())
		{
			fanPages.erase(itr);
			return;
		}
	}
}

void Admin::printAllPages() const
{
	list<FanPage>::const_iterator itr = fanPages.begin();
	list<FanPage>::const_iterator itrEnd = fanPages.end();
	int i = 0;
	int numOfPages = fanPages.size();

	if (numOfPages == 0)
	{
		cout << "None" << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
	{
		cout << "#" << ++i << " " << (*itr).getName() << endl;
	}
}