#include "Admin.h"
#include <string>
#include<vector>
using namespace std;

void Admin::printMenu()
{
	cout << endl;
	cout << "Please choose an action:" << endl;
	cout << "1 - Create a new memeber" << endl;
	cout << "2 - Create a new fan page" << endl;
	cout << "3 - Add status to a fan page or a member" << endl;
	cout << "4 - Show all fan page or member statuses" << endl;
	cout << "5 - Show 10 latest statuses of friends of a member" << endl;
	cout << "6 - Create friendship" << endl;
	cout << "7 - Delete friendship" << endl;
	cout << "8 - Add fan to fan page" << endl;
	cout << "9 - Remove a fan from fan page" << endl;
	cout << "10 - Show all accounts (members and fan pages)" << endl;
	cout << "11 - Show all friends of a member or fans that follows a fan page" << endl;
	cout << "12 - Exit" << endl;
	cout << "__________________________________________________________________________" << endl;
	cout << endl;
}

const vector<FanPage>& Admin:: getPagesArray() 
{
	return fanPages;
}

const vector<Member>& Admin::getMembersArray() 
{
	return users;
}

void Admin:: menu()
{
	int action;
	cout << "Wellcome to facebook!" << endl;
	do
	{
		printMenu();
		std::cin.sync();
		cin >> action;
		switch (action) {
		case 1:
			createMember();
			break;
		case 2:
			createFanPage();
			break;
		case 3:
			addStatusToFanPageOrMember();
			break;
		case 4:
			showAllStatusesOfMemberOrFanPage();
			break;
		case 5:
			showLast10StatusesOfFriendsOfMember();
			break;
		case 6:
			makeFriendship();
			break;
		case 7:
			unFriendship();
			break;
		case 8:
			ConnectFanToPage();
			break;
		case 9:
			disConnectFanAndPage();
			break;
		case 10:
			printAcounts();
			break;
		case 11:
			printAllFriendsOfMemberOrFanPage();
			break;
		}
		cout << endl;
	} while (action != 12);
	cout << "\033[32mBye Bye :)\033[0m";
}

void Admin::printAcounts() const
{
	cout << "All the members:" << endl;
	printAllMembers();
	cout << "All the pages:" << endl;
	printAllPages();
}

void Admin::createMember()
{
	Member* member = getDetailsForMember();
	users.push_back(*member);
}

Member* Admin::getDetailsForMember() const
{
	int day =0 , month =0, year=0;
	char slash_dummy;
	bool validDate = false;
	string name;
	getchar(); //clear the buffer 

	do {
		cout << "Please enter a name - max 20 letters" << endl;
		getline(std::cin, name);
	} while (checkIfNameExist(name));

	Date date(day, month, year);
	do {
		cout << "Please enter date of birth - format dd/mm/yyyy" << endl;
		cin >> day >> slash_dummy >> month >> slash_dummy >> year;
		validDate = date.setDate(day, month, year);
	} while (!validDate);

	Member* member = new Member (name, date);
	cout << name << "\033[32m was created :)\033[0m" << endl;
	return member;
}

void Admin::createFanPage()
{
	FanPage* fanPage = getDetailsForPage();
	fanPages.push_back(*fanPage);
}

FanPage* Admin::getDetailsForPage() const
{
	string name;
	getchar(); //clear the buffer 

	do {
		cout << "Please enter the name of the page- max 20 letters" << endl;
		getline(std::cin, name);
	} while (checkIfNameExist(name));

	FanPage* fanPage = new FanPage(name);
	cout << name << "\033[32m was created :)\033[0m" << endl;
	return fanPage;
}

Member* Admin::getMemberToAction() {
	Member* tmpMember = nullptr;
	string name;
	do
	{
		cout << "Please enter the name of the member from the list" << endl;
		getline(std::cin, name);

		tmpMember = getMember(name);
		if (tmpMember == nullptr)
		{
			cout << "\033[1;31mThe member not found Please enter another name.\033[0m" << endl;
		}
	} while (tmpMember == nullptr);
	return tmpMember;
}

FanPage* Admin::getFanPageToAction() {
	FanPage* tmpPage = nullptr;
	string name;
	do
	{
		cout << "Please enter the name of the fan page you want" << endl;
		getline(std::cin, name);
		tmpPage = findPage(name);
		if (tmpPage == nullptr)
		{
			cout << "\033[1;31mThe member not found Please enter another name.\033[0m" << endl;
		}
	} while (tmpPage == nullptr);
	return tmpPage;
}

void Admin::addStatusToFanPageOrMember() {
	int choice;
	string name;

	do {
		cout << "For a member enter 1 , For a Fan page enter 2" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			Member* tmpMember = nullptr;
			cout << "All the members:" << endl;
			printAllMembers();
			tmpMember = getMemberToAction();
			tmpMember->addStatus();
			cout << "\033[32mThe status was added :)\033[0m" << endl;
			return;
		}
		else if (choice==2) //to fan page
		{
			FanPage* tmpPage = nullptr;
			cout << "All the fan Pages:" << endl;
			printAllPages();
			tmpPage = getFanPageToAction();
			tmpPage->addStatus();
			cout << "\033[32mThe status was added :)\033[0m" << endl;
			return;
		}
		else
		{
			cout << "\033[1;31mInvalid input\033[0m" << endl;
		}
	} while ((choice != 1) || (choice != 2));
}

void Admin::showAllStatusesOfMemberOrFanPage()
{
	int choice;
	string name;

	do {
		cout << "For a member enter 1 , For a fan page enter 2" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			Member* tmpMember = nullptr;
			cout << "All the members:" << endl;
			printAllMembers();
			tmpMember = getMemberToAction();
			tmpMember->showMyStatuses();
			return;
		}
		else  //to fan page
		{
			FanPage* tmpPage = nullptr;
			cout << "All the fan pages:" << endl;
			printAllPages();
			tmpPage = getFanPageToAction();
			tmpPage->showMyStatuses();
			return;
		}
	} while ((choice != 1) || (choice != 2));

}

void Admin::makeFriendship()
{
	string name1;
	string name2;
	Member* member1;
	Member* member2 = nullptr;

	cout << "All the members:" << endl;
	printAllMembers();
	getchar(); //clear the buffer 
	do
	{
		do {
			cout << "Please Choose the first member" << endl;
			getline(std::cin, name1);
			member1 = getMember(name1);
			if (member1 == nullptr)
				cout << "\033[1;31mNo such user please try again.\033[0m" << endl;
		} while (member1 == nullptr);

		do {
			cout << "Please Choose the second member" << endl;
			getline(std::cin, name2);
			if (name1==name2)
			{
				cout << "\033[1;31mIts the same member as the first one, please enter another one.\033[0m" << endl;
			}
			else
			{
				member2 = getMember(name2);
			}

			if (member2==nullptr)
				cout << "\033[1;31mNo such user please try again.\033[0m" << endl;
		} while ((member2 == nullptr) || name1==name2);

		if ((!member1->checkFriendship(name2)))
		{
			member1->addFriend(*member2);
			cout << name1 << "\033[32m and \033[0m"  << name2 << "\033[32m are friends now :)\033[0m " << endl;
		}
		else
		{
			cout << "\033[1;31mThey are already friends.\033[0m" << endl;
		}

	} while (!member1->checkFriendship(name2));
}

void Admin::makeFriendship(Member& member1, Member& member2)
{
	member1.addFriend(member2);
}

void Admin::unFriendship()
{
	string name1;
	string name2;
	Member* member1;
	Member* member2 = nullptr;

	cout << "All the members:" << endl;
	printAllMembers();
	getchar(); //clear the buffer 

	do {
		cout << "Please Choose the first member" << endl;
		getline(std::cin, name1);
		member1 = getMember(name1);
		if (member1 == nullptr)
			cout << "\033[1;31mNo such user please try again.\033[0m" << endl;
	} while (member1 == nullptr);

	if (member1->getNumOfFriends() == 0)
	{
		cout << "\033[1;31mThis member doesn't have any friends yet.\033[0m" << endl;
		return;
	}
	else
	{
		member1->showFriends();
	}

	do {
		cout << "Please Choose the member you want to unfriend" << endl;
		getline(std::cin, name2);
		if (name1==name2)
		{
			cout << "\033[1;31mCan't unfriends yourself try a diffrent name.\033[0m" << endl;
		}
		else
		{
			member2 = getMember(name2);
			if (!member1->checkFriendship(name2))
				cout << "\033[1;31mThey are not friends, please choose another friend.\033[0m" << endl;
		}
	} while ((member2 == nullptr) || !member1->checkFriendship(name2));

	member1->unFriend(*member2);
	cout << endl <<name1 << "\033[32m and \033[0m" << name2 << "\033[32m are no longer friends :(\033[0m" << endl;
}

void Admin::disConnectFanAndPage()
{
	string nameOfMember;
	string nameOfPage;
	Member* member = nullptr;
	FanPage* page = nullptr;

	getchar(); //clear the buffer 
	do
	{
		cout << "All the fan pages:" << endl;
		printAllPages();
		page = getFanPageToAction();
		if (page->getNumOfFans() == 0)
		{
			cout << "\033[1;31mThis fanPage doesn't have any fans yet.\033[0m" << endl;
			return;
		}
		else
		{
			cout << page->getName() << "'s fans are:" << endl;
			page->printFans();
		}
		member = getMemberToAction();


		if (!(member->checkIfAlreadyFolowing(page->getName())))
		{
			cout << "\033[1;31mThis member doesn't follow this page.\033[0m" << endl;
		}

	} while (!member->checkIfAlreadyFolowing(page->getName()));

	member->disConnectPage(*page);
	cout << endl << member->getName() <<  "\033[32m is no longer follows \033[0m" << page->getName() << "\033[32m :(\033[0m" << endl;
}

void Admin::ConnectFanToPage(Member& member, FanPage& page) 
{
	member.followPage(page);
}


void Admin::ConnectFanToPage()
{
	string nameOfMember;
	string nameOfPage;
	Member* member = nullptr;
	FanPage* page = nullptr;

	cout << "All the members:" << endl;
	printAllMembers();
	do
	{
		getchar(); //clear the buffer 
		member = getMemberToAction();
		cout << "All the fanPages:" << endl;
		printAllPages();
		page = getFanPageToAction();
		if ((!member->checkIfAlreadyFolowing(page->getName())))
		{
			member->followPage(*page);
			cout << member->getName() << "\033[32m is now following \033[0m" << page->getName() << "\033[32m :) \033[0m" << endl;
		}
		else
		{
			cout << "\033[1;31mThey are already connected!\033[0m" << endl;
		}
	} while (!member->checkIfAlreadyFolowing(page->getName()));
	
}

void Admin::printAllFriendsOfMemberOrFanPage()
{
	int choice;
	string name;

	do {
		cout << "For a member enter 1 , For a fan page enter 2" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) 
		{
			Member* member;
			cout << "All the members:" << endl;
			printAllMembers();
			member = getMemberToAction();
			member->showFriends();
			member->showFanPages();
			break;
		}

		else if (choice == 2) 
		{
			FanPage* fanPage;
			cout << "All the Fan pages:" << endl;
			printAllPages();
			fanPage = getFanPageToAction();
			cout << fanPage->getName() << "'s fans are:" << endl;
			fanPage->printFans();
			break;
		}
		else
			cout << "\033[1;31mInvalid input\033[0m" <<endl;
	
	} while ((choice != 1) || (choice != 2));
}

void Admin::showLast10StatusesOfFriendsOfMember()
{
	string name;
	Member* member = nullptr;
	cout << "All the members:" << endl;
	printAllMembers();
	getchar(); //clear the buffer 
	member = getMemberToAction();
	if (member->getNumOfFriends() == 0)
	{
		cout << "\033[1;31mThe member doesnt have any friends.\033[0m" << endl;
	}
	else
	{
		member->Show10MyFriendsLastStatuses();
	}
}

void Admin::hardCodedData()
{
	FanPage* fanPage1 = new FanPage("mondial");
	FanPage* fanPage2 = new FanPage("re'evim beravcha");
	FanPage* fanPage3 = new FanPage("keren kalif fans");
	fanPages.push_back(*fanPage1);
	fanPages.push_back(*fanPage2);
	fanPages.push_back(*fanPage3);
	//FanPage* fanPage1 = fanPages.addPage("Mondial 2022");
	//FanPage* fanPage2 = fanPages.addPage("re'evim beravcha");
	//FanPage* fanPage3 = fanPages.addPage("keren kalif fans");

	Member* member1 = new Member("Boaz", Date(1, 1, 2020));
	Member* member2 = new Member("Romina", Date(2, 2, 2000));
	Member* member3 = new Member("Arie", Date(3, 3, 1997));
	users.push_back(*member1);
	users.push_back(*member2);
	users.push_back(*member3);

	//Member* member1 = users.addMember("Boaz", Date(1, 1, 2020));
	//Member* member2 = users.addMember("Romina", Date(2, 2, 2000));
	//Member* member3 = users.addMember("Arie", Date(3, 3, 1997));

	member1->addStatus("Hey its Boaz");
	member1->addStatus("Boaz 2");
	member2->addStatus("Hey its Romina");
	member2->addStatus("Romina 2");
	member3->addStatus("Hey its Arie");
	member3->addStatus("Arie 2");
	fanPage1->addStatus("welcome to Mondial 2022");
	fanPage1->addStatus("Mondial 2022");
	fanPage2->addStatus("welcome to re'evim beravcha");
	fanPage2->addStatus("re'evim beravcha 2");
	fanPage3->addStatus("welcome to keren kalif fans");
	fanPage3->addStatus("keren kalif fans 2");

	*member1 += *member2;
	*member1 += *member3;
	*member1 += *fanPage1;
	*fanPage2 += *member1;
	*member2 += *fanPage1;

	//cout << (*member1 > *member2); T
	//cout << (*member1 > *fanPage1); F
	//cout << (*fanPage2 > *member3); F
	//cout << (*fanPage1 > *fanPage2); T

	//Status test1("M");
	//Status test2("m");
	//cout << (test1 == test2); F
	//cout << (test1 != test2); T
}

//from members array
bool Admin::checkIfNameExist(const string name) const
{
	vector<Member>::const_iterator itr = users.begin();
	vector<Member>::const_iterator itrEnd = users.end();

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

void Admin::addMember(Member& m)
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
	users.push_back(m);
	//membersArray[numOfMembers] = &m;
	//numOfMembers++;
}

Member* Admin::addMember(const string name, const Date& dateOfBirth)
{
	Member* member = new Member(name, dateOfBirth);

	//if (numOfMaxMembers == numOfMembers) {
	//	numOfMaxMembers = numOfMaxMembers * 2;
	//	Member** tmp = new Member * [numOfMaxMembers];
	//	for (int i = 0; i < numOfMembers; i++)
	//		tmp[i] = membersArray[i];
	//	membersArray = tmp;
	//	tmp = nullptr;
	//	delete[] tmp;
	//}
	users.push_back(*member);
	return member;
	/*membersArray[numOfMembers] = member1;
	numOfMembers++;
	return member1;*/
}

void Admin::deleteMember(Member& member)
{
	vector<Member>::iterator itr = users.begin();
	vector<Member>::iterator itrEnd = users.end();

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

	vector<Member>::const_iterator itr = users.begin();
	vector<Member>::const_iterator itrEnd = users.end();
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
	vector<Member>::iterator itr = users.begin();
	vector<Member>::iterator itrEnd = users.end();

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
	vector<Member>::const_iterator itr = users.begin();
	vector<Member>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr).printMyLast10Statuses();
	}
}

//from pages array
void Admin::deletePage(FanPage& page)
{
	vector<FanPage>::iterator itr = fanPages.begin();
	vector<FanPage>::iterator itrEnd = fanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName() == page.getName())
		{
			fanPages.erase(itr);
			return;
		}
	}
}

void Admin::addPage(FanPage& p)
{
	fanPages.push_back(p);
}

FanPage* Admin::addPage(const string name)
{
	FanPage* fanPage = new FanPage(name);
	fanPages.push_back(*fanPage);
	return fanPage;
}

void Admin::printAllPages() const
{
	vector<FanPage>::const_iterator itr = fanPages.begin();
	vector<FanPage>::const_iterator itrEnd = fanPages.end();
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

FanPage* Admin::findPage(string name)
{
	FanPage* theFoundPage = nullptr;
	vector<FanPage>::iterator itr = fanPages.begin();
	vector<FanPage>::iterator itrEnd = fanPages.end();

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
