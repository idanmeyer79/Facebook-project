#include "Admin.h"
#include <string>
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

const PagesArray& Admin:: getPagesArray() const
{
	return fanPages;
}

const MembersArray& Admin::getMembersArray() const
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
	} while (action != 12);
	cout << "Bye Bye :)";
}

void Admin::printAcounts() const
{
	cout << "All the members:" << endl;
	users.printAllMembers();
	cout << "All the pages:" << endl;
	fanPages.printAllPages();
}

void Admin::createMember()
{
	Member* member = getDetailsForMember();
	users.addMember(*member);
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
	} while (users.checkIfNameExist(name));

	Date date(day, month, year);
	do {
		cout << "Please enter date of birth - format dd/mm/yyyy" << endl;
		cin >> day >> slash_dummy >> month >> slash_dummy >> year;
		validDate = date.setDate(day, month, year);
	} while (!validDate);

	Member* member = new Member (name, date);
	cout << name << " was created :)" << endl;
	return member;
}

void Admin::createFanPage()
{
	FanPage* fanPage = getDetailsForPage();
	fanPages.addPage(*fanPage);
}

FanPage* Admin::getDetailsForPage() const
{
	string name;
	getchar(); //clear the buffer 

	do {
		cout << "Please enter the name of the page- max 20 letters" << endl;
		getline(std::cin, name);

	} while (fanPages.checkIfNameExist(name));

	FanPage* fanPage = new FanPage(name);
	cout << name << " was created :)" << endl;
	return fanPage;
}

Member* Admin::getMemberToAction() {
	Member* tmpMember = nullptr;
	char name[LEN_OF_NAME];
	do
	{
		cout << "Please enter the name of the member from the list" << endl;
		cin.getline(name, LEN_OF_NAME);
		tmpMember = users.getMember(name);
		if (tmpMember == nullptr)
		{
			cout << "The member was not found Please enter another name" << endl;
		}
	} while (tmpMember == nullptr);
	return tmpMember;
}

FanPage* Admin::getFanPageToAction() {
	FanPage* tmpPage = nullptr;
	char name[LEN_OF_NAME];
	do
	{
		cout << "Please enter the name of the paeg from the list" << endl;
		cin.getline(name, LEN_OF_NAME);
		tmpPage = fanPages.findPage(name);
		if (tmpPage == nullptr)
		{
			cout << "The page was not found Please enter another name" << endl;
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
			users.printAllMembers();
			tmpMember = getMemberToAction();
			tmpMember->addStatus();
			cout << "The status was added :)" << endl;
			return;
		}
		else if (choice==2) //to fan page
		{
			FanPage* tmpPage = nullptr;
			cout << "All the fan Pages:" << endl;
			fanPages.printAllPages();
			tmpPage = getFanPageToAction();
			tmpPage->addStatus();
			cout << "The status was added :)" << endl;
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
			users.printAllMembers();
			tmpMember = getMemberToAction();
			tmpMember->showMyStatuses();
			return;
		}
		else  //to fan page
		{
			FanPage* tmpPage = nullptr;
			cout << "All the fan pages:" << endl;
			fanPages.printAllPages();
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
	users.printAllMembers();
	getchar(); //clear the buffer 
	do
	{
		do {
			cout << "Please Choose the first member" << endl;
			getline(std::cin, name1);
			member1 = users.getMember(name1);
			if (member1 == nullptr)
				cout << "No such user please try again"<<endl;
				
		} while (member1 == nullptr);

		do {
			cout << "Please Choose the second member" << endl;
			getline(std::cin, name2);
			if (name1==name2)
			{
				cout << "Its the same member as the first one, please enter another one" << endl;
			}
			else
			{
				member2 = users.getMember(name2);
			}

			if (member2==nullptr)
				cout << "No such user please try again" << endl;

		} while ((member2 == nullptr) || name1==name2);

		if ((!member1->checkFriendship(name2)))
		{
			member1->addFriend(*member2);
			cout << name1 << " and " << name2 << " are friends now :) " << endl;
		}
		else
		{
			cout << "They are already friends" << endl;
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
	users.printAllMembers();
	getchar(); //clear the buffer 

	do {
		cout << "Please Choose the first member" << endl;
		getline(std::cin, name1);
		member1 = users.getMember(name1);
		if (member1 == nullptr)
			cout << "No such user please try again" << endl;

	} while (member1 == nullptr);

	if (member1->getNumOfFriends() == 0)
	{
		cout << "This member doesn't have any friends yet" << endl;
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
			cout << "Can't unfriends yourself try a diffrent name" << endl;
		}
		else
		{
			member2 = users.getMember(name2);
			if (!member1->checkFriendship(name2))
				cout << "They are not friends, please choose another friend" << endl;
		}
	} while ((member2 == nullptr) || !member1->checkFriendship(name2));

	member1->unFriend(*member2);
	cout << endl <<name1 << " and " << name2 << " are no longer friends :(" << endl;
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
		fanPages.printAllPages();
		page = getFanPageToAction();
		if (page->getNumOfFans() == 0)
		{
			cout << "This fanPage doesn't have any fans yet" << endl;
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
			cout << "This member doesn't follow this page " << endl;
		}

	} while (!member->checkIfAlreadyFolowing(page->getName()));

	member->disConnectPage(*page);
	cout << endl << member->getName() << " is no longer follows " << page->getName() << " :(" << endl;
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
	users.printAllMembers();
	do
	{
		getchar(); //clear the buffer 
		member = getMemberToAction();
		cout << "All the fanPages:" << endl;
		fanPages.printAllPages();
		page = getFanPageToAction();
		if ((!member->checkIfAlreadyFolowing(page->getName())))
		{
			member->followPage(*page);
			cout << member->getName() << " is now following " << page->getName() << " :) " << endl;
		}
		else
		{
			cout << "They are already connected!" << endl;
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
			users.printAllMembers();
			member = getMemberToAction();
			member->showFriends();
			member->showFanPages();
			break;
		}

		else if (choice == 2) 
		{
			FanPage* fanPage;
			fanPages.printAllPages();
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
	users.printAllMembers();
	getchar(); //clear the buffer 
	member = getMemberToAction();
	if (member->getNumOfFriends() == 0)
	{
		cout << "The member doesnt have any friends" << endl;
	}
	else
	{
		member->Show10MyFriendsLastStatuses();
	}
}

void Admin::hardCodedData()
{
	FanPage* fanPage1 = fanPages.addPage("Mondial 2022");
	FanPage* fanPage2 = fanPages.addPage("re'evim beravcha");
	FanPage* fanPage3 = fanPages.addPage("keren kalif fans");

	Member* member1 = users.addMember("Boaz", Date(1, 1, 2020));
	Member* member2 = users.addMember("Romina", Date(2, 2, 2000));
	Member* member3 = users.addMember("Arie", Date(3, 3, 1997));

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

	Status test1("M");
	Status test2("m");

	//cout << (test1 == test2); F
	//cout << (test1 != test2); T
}
