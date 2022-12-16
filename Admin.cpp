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
	cout << "10 - Show all acounts (members and fan pages)" << endl;
	cout << "11 - Show all friends of a member or fans that follows a fan page" << endl;
	cout << "12 - Exit" << endl;
	cout << "__________________________________________________________________________" << endl;
	cout << endl;
}

PagesArray& Admin:: getPagesArray()
{
	return fanPages;
}

MembersArray& Admin::getMembersArray()
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
			users.printAllMembers();
			fanPages.printAllPages();
			break;
		case 11:
			printAllFriendsOfMemberOrFanPage();
			break;
		}

	} while (action != 12);
	cout << "Bye Bye :)";
}

void Admin::createMember()
{
	Member* member = getDetailsForMember();
	users.addMember(*member);
}

Member* Admin::getDetailsForMember()
{
	int day =0 , month =0, year=0;
	char slash_dummy;
	string name;
	getchar(); //clear the buffer 

	do {
		cout << "Please enter a name - max 20 letters" << endl;
		getline(std::cin, name);
		//cin.getline(name, LEN_OF_NAME);
	} while (users.checkIfNameExist(name));

	Date date(day, month, year);
	do {
		cout << "Please enter date of birth - format dd/mm/yyyy" << endl;
		cin >> day >> slash_dummy >> month >> slash_dummy >> year;
		date.setDate(day, month, year);
	} while (!date.checkdate());

	Member* member = new Member (name, date);
	return member;
}

void Admin::createFanPage()
{
	FanPage* fanPage = getDetailsForPage();
	fanPages.addPage(*fanPage);
}

FanPage* Admin::getDetailsForPage()
{
	string name;
	getchar(); //clear the buffer 

	do {
		cout << "Please enter the name of the page- max 20 letters" << endl;
		getline(std::cin, name);

		//cin.getline(name, LEN_OF_NAME);
	} while (fanPages.checkIfNameExist(name));

	FanPage* fanPage = new FanPage(name);
	return fanPage;
}

void Admin::addStatusToFanPageOrMember() {
	int choice;
	string name;

	do {
		cout << "If you want to add status to member enter 1, if you want to add status to a fan page enter 2" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			Member* tmpMember = nullptr;
			users.printAllMembers();
			do
			{
				cout << "Please enter the name of the member from the list" << endl;
				getline(std::cin, name);

				//cin.getline(name, LEN_OF_NAME);
				tmpMember = users.getMember(name);
				if (tmpMember == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpMember == nullptr);

			tmpMember->addStatus();
			return;
		}
		else //to fan page
		{
			FanPage* tmpPage = nullptr;
			fanPages.printAllPages();
			do
			{
				cout << "Please enter the name of the paeg from the list" << endl;
				getline(std::cin, name);
				tmpPage = fanPages.findPage(name);
				if (tmpPage == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpPage == nullptr);

			tmpPage->addStatus();
			return;
		}
	} while ((choice != 1) || (choice != 2));
}

void Admin::showAllStatusesOfMemberOrFanPage()
{
	int choice;
	string name;

	do {
		cout << "Enter 1 to choose a member, 2 to choose a fan page or 3 to go back to main menu" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) //to member
		{
			Member* tmpMember = nullptr;
			users.printAllMembers();
			do
			{
				cout << "Please enter the name of the member from the list" << endl;
				getline(std::cin, name);
				tmpMember = users.getMember(name);
				if (tmpMember == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpMember == nullptr);
			tmpMember->showMyStatuses();
			return;
		}
		else  //to fan page
		{
			FanPage* tmpPage = nullptr;
			fanPages.printAllPages();
			do
			{
				cout << "Please enter the name of the fan page you want" << endl;
				getline(std::cin, name);
				tmpPage = fanPages.findPage(name);
				if (tmpPage == nullptr)
				{
					cout << "The member not found Please enter another name" << endl;
				}
			} while (tmpPage == nullptr);			
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
			if (name1==name2)//!(strcmp(name1, name2)))
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
		}
		else
		{
			cout << "They are already friends";
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
		cout << "Please Choose the second member" << endl;
		getline(std::cin, name2);
		if (name1==name2)//!(strcmp(name1, name2)))
		{
			cout << "Its the same member as the first one, please enter another one" << endl;
		}
		else
		{
			member2 = users.getMember(name2);
			if (!member1->checkFriendship(name2))
				cout << "They are not friends, please choose another friend" << endl;
		}
	} while ((member2 == nullptr) || !member1->checkFriendship(name2));

	member1->unFriend(*member2);
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
		fanPages.printAllPages();
		do {
			cout << "Please Choose the fan page" << endl;
			getline(std::cin, nameOfPage);
			page = fanPages.findPage(nameOfPage);
			if (page == nullptr)
				cout << "No such page please try again" << endl;
		} while ((page == nullptr));

		if (page->getNumOfFans() == 0)
		{
			cout << "This fanPage doesn't have any fans yet" << endl;
			return;
		}
		else
		{
			page->printFans();
		}

		do {
			cout << "Please Choose the member" << endl;
			getline(std::cin, nameOfMember);
			member = users.getMember(nameOfMember);
			if (member == nullptr)
				cout << "No such user please try again" << endl;
		} while (member == nullptr);

		if (!(member->checkIfAlreadyFolowing(nameOfPage)))
		{
			cout << "This member doesn't follow this page " << endl;
		}

	} while (!member->checkIfAlreadyFolowing(nameOfPage));

	member->disConnectPage(*page);
}

void Admin::ConnectFanToPage(Member& member, FanPage& page) 
{
	member.followPage(page);
}

void Admin::ConnectFanToPage() //להודפיס את כל הדפים שהחבר הנחבר עוקב אחריהם
{
	string nameOfMember;
	string nameOfPage;
	Member* member = nullptr;
	FanPage* page = nullptr;

	users.printAllMembers();

	do
	{
		getchar(); //clear the buffer 
		do {
			cout << "Please Choose the member" << endl;
			getline(std::cin, nameOfMember);
			member = users.getMember(nameOfMember);
			if (member == nullptr)
				cout << "No such user please try again" << endl;
		} while (member == nullptr);

		do {
			fanPages.printAllPages();
			cout << "Please Choose the fan page" << endl;
			getline(std::cin, nameOfPage);
			page = fanPages.findPage(nameOfPage);
			if (page == nullptr)
				cout << "No such page please try again" << endl;
		} while ((page == nullptr));

		if ((!member->checkIfAlreadyFolowing(nameOfPage)))
		{
			member->followPage(*page);
		}
		else
		{
			cout << "They are already connected";
		}
	} while (!member->checkIfAlreadyFolowing(nameOfPage));
	
}

void Admin::printAllFriendsOfMemberOrFanPage()
{
	int choice;
	string name;

	do {
		cout << "Enter 1 to choose a member, 2 to choose a fan page or 3 to go back to main menu" << endl;
		cin >> choice;
		getchar(); //clear the buffer 

		if (choice == 1) 
		{
			Member* member;
			users.printAllMembers();
			do
			{
				cout << "Please enter the name of the member from the list" << endl;
				getline(std::cin, name);
				member = users.getMember(name);
				if (member == nullptr)
				{
					cout << "The member not not found Please enter another name" << endl;
				}
			} while (member == nullptr);
			member->showFriends();
			member->showFanPages();
		}

		else if (choice == 2) 
		{
			FanPage* fanPage;
			fanPages.printAllPages();
			do
			{
				cout << "Please enter the name of the page from the list" << endl;
				getline(std::cin, name);
				fanPage = fanPages.findPage(name);
				if (fanPage == nullptr)
				{
					cout << "The page was not found Please enter another name" << endl;
				}
			} while (fanPage == nullptr);
			fanPage->printFans();
		}

		else if (choice == 3)
			break;

		else
			cout << "Ivalid input"<<endl;
	

	} while ((choice != 1) || (choice != 2));
}

void Admin::showLast10StatusesOfFriendsOfMember()
{
	string name;
	Member* member = nullptr;

	users.printAllMembers();
	getchar(); //clear the buffer 

	do {
		cout << "Please Choose the first member" << endl;
		getline(std::cin, name);
		//cin.getline(name, LEN_OF_NAME);
		member = users.getMember(name);
		if (member == nullptr)
			cout << "No such user please try again" << endl;
	} while (member == nullptr);

	member->Show10MyFriendsLastStatuses();
}

void Admin::hardCodedData()
{
	string M = "M";	
	string reevim = "re'evim beravcha";
	string keren = "keren kalif fans";
	FanPage* fanPage1 = fanPages.addPage("M");
	FanPage* fanPage2 = fanPages.addPage("re'evim beravcha");
	FanPage* fanPage3 = fanPages.addPage("keren kalif fans");

	Member* member1 = users.addMember((string)"Boaz", Date(1, 1, 2020));
	Member* member2 = users.addMember((string)"Romina", Date(2, 2, 2000));
	Member* member3 = users.addMember((string)"Arie", Date(3, 3, 1997));

	member1->addStatus((string)"Hey its Boaz");
	member1->addStatus((string)"Boaz 2");
	member2->addStatus((string)"Hey its Romina");
	member2->addStatus((string)"Romina 2");
	member3->addStatus((string)"Hey its Arie");
	member3->addStatus((string)" Arie 2");
	fanPage1->addStatus((string)"welcome to Mondial LEN_OF_NAME22");
	fanPage1->addStatus((string)"Mondial LEN_OF_NAME22 2");
	fanPage2->addStatus((string)"welcome to re'evim beravcha");
	fanPage2->addStatus((string)"re'evim beravcha 2");
	fanPage3->addStatus((string)"welcome to keren kalif fans");
	fanPage3->addStatus((string)"keren kalif fans 2");

	///לממחוק לפני ההגשה
	member2->addStatus((string)"3");
	member2->addStatus((string)"4");
	member2->addStatus((string)"5");
	member2->addStatus((string)"6");
	member2->addStatus((string)"7");
	member2->addStatus((string)"8");
	member2->addStatus((string)"9");
	member2->addStatus((string)"10");
	member2->addStatus((string)"11");
	member2->addStatus((string)"12");

	makeFriendship(*member1, *member2);
	makeFriendship(*member1,*member3);
	ConnectFanToPage(*member1, *fanPage1);
	ConnectFanToPage(*member1, *fanPage2);
	ConnectFanToPage(*member2, *fanPage1);
}
