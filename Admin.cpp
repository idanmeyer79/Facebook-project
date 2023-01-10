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

void Admin::saveToFileBinary(const std::list<FanPage>& fanPages, const std::list<Member>& users, const std::string& fileName) {
	std::ofstream outFile(fileName, std::ios::binary);
	if (outFile.is_open()) {
		// Save the number of fan pages and users
		size_t fanPageCount = fanPages.size();
		outFile.write(reinterpret_cast<const char*>(&fanPageCount), sizeof(size_t));
		size_t userCount = users.size();
		outFile.write(reinterpret_cast<const char*>(&userCount), sizeof(size_t));

		// Save the fan pages
		for (const FanPage& fanPage : fanPages) {
			// Save the page name
			size_t pageNameSize = fanPage.getName().size();
			outFile.write(reinterpret_cast<const char*>(&pageNameSize), sizeof(size_t));
			outFile.write(fanPage.getName().c_str(), pageNameSize);

			// Save the fans
			size_t fanCount = fanPage.getNumOfFans();
			outFile.write(reinterpret_cast<const char*>(&fanCount), sizeof(size_t));
			for (const Member* fan : fanPage.getFans()) {
				size_t fanNameSize = fan->getName().size();
				outFile.write(reinterpret_cast<const char*>(&fanNameSize), sizeof(size_t));
				outFile.write(fan->getName().c_str(), fanNameSize);
			}

			//Save statuses
			size_t statusCount = fanPage.getNumOfStatuses();
			outFile.write(reinterpret_cast<const char*>(&statusCount), sizeof(size_t));
			for (const Status* status : fanPage.getStatuses())
			{
				const string Type = typeid(*status).name() + 6;
				outFile.write(Type.c_str(), Type.size());
				outFile.write(reinterpret_cast<const char*>(status), sizeof(Status));
			}
		}

		// Save the users
		for (const Member& user : users) {
			// Save the member name
			size_t memberNameSize = user.getName().size();
			outFile.write(reinterpret_cast<const char*>(&memberNameSize), sizeof(size_t));
			outFile.write(user.getName().c_str(), memberNameSize);
			//Save the Date of birth
			Date userDOB = user.getDate();
			outFile.write(reinterpret_cast<const char*>(&userDOB), sizeof(Date));


			// Save the member statuses
			size_t statusCount = user.getMemberStatuses().size();
			outFile.write(reinterpret_cast<const char*>(&statusCount), sizeof(size_t));
			for (const Status* status : user.getMemberStatuses())
			{
				const string Type = typeid(*status).name() + 6;
				outFile.write(Type.c_str(), Type.size());
				outFile.write(reinterpret_cast<const char*>(status), sizeof(Status));
			}

			// Save the member fan pages
			size_t fanPageCount = user.getPagesArray().size();
			outFile.write(reinterpret_cast<const char*>(&fanPageCount), sizeof(size_t));
			for (const FanPage* fanPage : user.getPagesArray()) {
				size_t fanPageNameSize = fanPage->getName().size();
				outFile.write(reinterpret_cast<const char*>(&fanPageNameSize), sizeof(size_t));
				outFile.write(fanPage->getName().c_str(), fanPageNameSize);
			}
			// Save the member friends
			size_t friendCount = user.getMembersArray().size();
			outFile.write(reinterpret_cast<const char*>(&friendCount), sizeof(size_t));
			for (const Member* userFriend : user.getMembersArray()) {
				size_t friendNameSize = userFriend->getName().size();
				outFile.write(reinterpret_cast<const char*>(&friendNameSize), sizeof(size_t));
				outFile.write(userFriend->getName().c_str(), friendNameSize);
			}
		}

		outFile.close();
	}
	else {
		// Error: unable to open file for writing
	}
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
			outFile << fanPage.getName() << '\n';

			// Save the fans
			outFile << fanPage.getNumOfFans() << '\n';
			for (const Member* fan : fanPage.getFans()) {
				//size_t fanIndex = std::distance(users.begin(), std::find(users.begin(), users.end(), *fan));
				//outFile << fanIndex << '\n';
				outFile << fan->getName() << '\n';
			}

			//Save statuses
			outFile << fanPage.getNumOfStatuses()<< '\n';
			for (const Status* status : fanPage.getStatuses())
			{
				outFile << typeid(*status).name() + 6 << endl;
				outFile << *status << '\n';
			}
		}

		// Save the users
		for (const Member& user : users) {
			// Save the member name
			outFile << user.getName() << '\n';
			//Save the Date of birth
			const Date DOB = user.getDate();
			outFile << DOB << '\n';

			// Save the member statuses
			outFile << user.getMemberStatuses().size() << '\n';
			for (const Status* status : user.getMemberStatuses())
			{
				outFile << typeid(*status).name() + 6 << endl;
				outFile << *status << '\n';

			}

			// Save the member fan pages
			outFile << user.getPagesArray().size() << '\n';
			for (const FanPage* fanPage : user.getPagesArray()) {
				//size_t fanPageIndex = std::distance(fanPages.begin(), std::find(fanPages.begin(), fanPages.end(), *fanPage));
				//outFile << fanPageIndex << '\n';
				outFile << fanPage->getName() << '\n';


			}

			// Save the member friends
			outFile << user.getMembersArray().size() << '\n';
			for (const Member* userfriend : user.getMembersArray()) {
				//size_t friendIndex = std::distance(users.begin(), std::find(users.begin(), users.end(), *userfriend));
				//outFile << friendIndex << '\n';
				outFile << userfriend->getName() << '\n';

			}
		}

		outFile.close();
	}
	else {
		// Error: unable to open file for writing
	}
}

