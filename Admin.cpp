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

void Admin::printAccounts() const
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

void Admin::addStatusToMember(Member* member, Status* status)
{
	member->addStatus(status);
}

void Admin::addStatusToPage(FanPage* page, Status* status)
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

void Admin::ConnectFanToPage(Member& member, FanPage& page) const
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
			return true;
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
			return true;
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
		cout << "#" << ++i << " " << (*itr).getName() << endl;
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

FanPage* Admin::getPage(const string name)
{
	list<FanPage>::iterator itr = fanPages.begin();
	list<FanPage>::iterator itrEnd = fanPages.end();

	FanPage* theFoundPage = nullptr;

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == name)
		{
			theFoundPage = &(*itr);
			return theFoundPage;
		}
	}
	return theFoundPage;
}

void Admin::showLast10StatusesOfEach() const
{
	list<Member>::const_iterator itr = users.begin();
	list<Member>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
		(*itr).printMyLast10Statuses();
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
		cout << "#" << ++i << " " << (*itr).getName() << endl;
}


void Admin::saveToFileText(const std::list<FanPage>& fanPages, const std::list<Member>& users, const std::string& fileName) {
	std::ofstream outFile(fileName);
	if (outFile.is_open()) {
		// Save the number of fan pages and users
		outFile <<fanPages.size() << '\n';
		outFile << users.size() << '\n';

		// Save the fan pages
		for (const FanPage& fanPage : fanPages) {
			// Save the page name
			fanPage.saveToFile(outFile);
		}

		// Save the users
		for (const Member& user : users) 
			user.saveToFile(outFile);

		// Save connections

		for (const Member& user : users) 
		{
			
			// Save the member fan pages
			outFile << user.getPagesArray().size() << '\n';
			for (const FanPage* fanPage : user.getPagesArray()) {
				outFile << fanPage->getName() << '\n';
			}

			// Save the member friends
			outFile << user.getMembersArray().size() << '\n';
			for (const Member* userfriend : user.getMembersArray()) {
				outFile << userfriend->getName() << '\n';
			}
		}


		outFile.close();
	}
	else {
		// Error: unable to open file for writing
	}
}

void Admin::loadFromFile(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName);
	string memberToConnect, pageToConncet;
	FanPage* tempPage;
	Member* tempMember;
	int numOfPagesToFollow, NumOfFriend;
	if (file.is_open()) {
		int numOfUsers, numOfPages;
        file >> numOfPages;
        file >> numOfUsers;
		file.ignore();
        for (int i = 0; i < numOfPages; i++) {
			FanPage page(file);
            fanPages.push_back(page);
        }
		for (int i = 0; i < numOfUsers; i++) {
			Member user(file);
			users.push_back(user);
		}

		for (Member& user : users)
		{
			file >> numOfPagesToFollow;
			file.ignore();
			for (int i = 0; i < numOfPagesToFollow; i++)
			{
				getline(file, pageToConncet);
				if (!user.checkIfAlreadyFolowing(pageToConncet))
				{
					tempPage = getPage(pageToConncet);
					ConnectFanToPage(user, *tempPage);
				}
			}
			file >> numOfPagesToFollow;
			file.ignore();
			for (int i = 0; i < numOfPagesToFollow; i++)
			{
				getline(file, memberToConnect);
				if (!user.checkFriendship(memberToConnect))
				{
					tempMember = getMember(memberToConnect);
					makeFriendship(user, *tempMember);
				}
			}

		}
        file.close();
    } else {
        cout << "Unable to open file";
    }
}

