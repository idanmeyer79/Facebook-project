#include "FacebookIO.h"
#include"member.h"
#include "StatusWithVideo.h"
#include "StatusWithPhoto.h"
#include <iostream>
using namespace std;

constexpr int TEXT_STATUS = 1;
constexpr int PHOTO_STATUS = 2;
constexpr int VIDEO_STATUS = 3;

void FacebookIO::displayMessage(const string& message) const {
    cout << message << endl;
}

string FacebookIO::getUserInput() {
    string input;
    getline(cin, input);
    return input;
}

void FacebookIO::wellcome()
{
    std::cout << "\033[1;31mW\033[0m" << "\033[1;33mE\033[0m" << "\033[1;32mL\033[0m" << "\033[1;34mL\033[0m"
        << "\033[1;35mC\033[0m" << "\033[1;36mO\033[0m" << "\033[1;37mM\033[0m" << "\033[1;31mE\033[0m"
        << "\033[1;32m \033[0m" << "\033[1;33mT\033[0m" << "\033[1;34mO\033[0m" << "\033[1;35m \033[0m"
        << "\033[1;36mF\033[0m" << "\033[1;37mA\033[0m" << "\033[1;31mC\033[0m" << "\033[1;32mE\033[0m"
        << "\033[1;33mB\033[0m" << "\033[1;34mO\033[0m" << "\033[1;35mO\033[0m" << "\033[1;36mK\033[0m" << std::endl;
}

void FacebookIO::printMenu()
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

Member FacebookIO::getDetailsForMember()
{
	int day = 0, month = 0, year = 0;
	char slash_dummy;
	bool validDate = false;
	bool validName = false;
	string name;
	getchar(); //clear the buffer 

	while (!validName)
	{
		try
		{
			cout << "Please enter a name - max 20 letters" << endl;
			name = getNewNameForNewMember();
			validName = true;
		}
		catch (const invalid_argument& e) { cout << "Error: " << e.what() << endl; }
		catch (const string& e) {nameAlreadyTaken();}
		catch (...) { cout << "Unknown error" << endl; }
	}

	while (true)
	{
		cout << "Please enter date of birth - format dd/mm/yyyy" << endl;
		cin >> day >> slash_dummy >> month >> slash_dummy >> year;
		try
		{
			Date date(day, month, year);
			Member member(name, date);
			return member;
		}

		catch (const invalid_argument& e) {cout << "Error: " << e.what() << endl;}
		catch (const exception& e) {cout << "Error: " << e.what() << endl;}
		catch (...) {cout << "Unknown error" << endl;}
	}
}

FanPage FacebookIO::getDetailsForPage() 
{
	string name;
	bool validName = false;
	getchar(); //clear the buffer 

	while (!validName)
	{
		try
		{
			cout << "Please enter a name - max 20 letters" << endl;
			name = getNewNameForNewFanPage();
			validName = true;
		}
		catch (const invalid_argument& e) { cout << "Error: " << e.what() << endl; }
		catch (const string& e) { nameAlreadyTaken(); }
		catch (...) { cout << "Unknown error" << endl; }
	}

	FanPage fanPage(name);
	return fanPage;
}

Status* FacebookIO::getStatusFromUser()
{
	int selector = selectTypeOfStatus();
	getchar();
	displayMessage("Please enter a new status: ");
	string text = getUserInput();

	if (selector == TEXT_STATUS)
	{
		Status* status= new Status(text);
		return status;
	}
	else if (selector == PHOTO_STATUS)
	{
		displayMessage("Please enter a color for the status: ");
		string color= getUserInput();
		Status* status = new StatusWithPhoto(text, color);
		return status;
	}
	else if (selector == VIDEO_STATUS)
	{
		displayMessage("Please enter a color for the status: ");
		string color= getUserInput();
		Status* status = new StatusWithVideo (text, color);
		return status;
	}
}

int FacebookIO::selectMemberOrPage()
{
	int selector;
	displayMessage("For a member enter 1, For a Fan page enter 2");
	cin >> selector;
	return selector;
}

int FacebookIO::selectTypeOfStatus()
{
	int selector;
	displayMessage("For a text status enter 1, For a photo and text status enter 2, For a video and text status enter 3");
	cin >> selector;
	return selector;
}

Member* FacebookIO::getMember(const string name)
{
	list<Member>::iterator itr = admin->users.begin();
	list<Member>::iterator itrEnd = admin->users.end();

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

FanPage* FacebookIO::getPage(const string name)
{
	list<FanPage>::iterator itr = admin->fanPages.begin();
	list<FanPage>::iterator itrEnd = admin->fanPages.end();

	FanPage* theFoundMember = nullptr;

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

void FacebookIO::printAllMembers() const
{
	list<Member>::const_iterator itr = admin->users.begin();
	list<Member>::const_iterator itrEnd = admin->users.end();
	int numOfMembers = admin->users.size();
	int i = 0;
	if (numOfMembers == 0)
	{
		cout << "None" << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
		cout << "#" << ++i << " " << (*itr).getName() << endl;
}

void FacebookIO::printAllPages() const
{
	list<FanPage>::const_iterator itr = admin->fanPages.begin();
	list<FanPage>::const_iterator itrEnd = admin->fanPages.end();
	int numOfMembers = admin->users.size();
	int i = 0;
	displayMessage("All the pages: ");
	if (numOfMembers == 0)
	{
		cout << "None" << endl;
		return;
	}

	for (; itr != itrEnd; ++itr)
		cout << "#" << ++i << " " << (*itr).getName() << endl;
}

void FacebookIO::printAllMemberStatuses(const Member& member) const
{
	member.printAllStatuses();
}

void FacebookIO::printAllPageStatuses(const FanPage& page) const
{
	page.printAllStatuses();
}

string FacebookIO::getNewNameForNewMember()
{
	string name;
	getline(cin, name);
	if (admin->checkIfUserNameExist(name))
		throw string(name);
	if (name.size() > MAX_LEN_OF_NAME)
		throw invalid_argument("\033[1;31mName is too long\033[0m");
	return name;
}

std::string FacebookIO::getNewNameForNewFanPage()
{
	string name;
	getline(cin, name);
	if (admin->checkIfPageNameExist(name))
		throw string(name);
	if (name.size() > MAX_LEN_OF_NAME)
		throw invalid_argument("\033[1;31mName is too long\033[0m");
	return name;
}

Member* FacebookIO::chooseMemberFromList()
{
	displayMessage("All the members : ");
	printAllMembers();
	displayMessage("Please enter the member's name from the list: ");
	string name = getUserInput();
	Member* member = getMember(name);
	if (!member)
		throw name;
	return member;
}

FanPage* FacebookIO::chooseFanPageFromList()
{
	printAllPages();
	displayMessage("Please enter the page's name from the list: ");
	string name = getUserInput();
	FanPage* page = getPage(name);
	if (!page)
		throw name;
	return page;
}

Member* FacebookIO:: getMemberException()
{
	Member* member = nullptr;
	getchar();
	while (!member)
	{
		try
		{
			member = chooseMemberFromList();
		}
		catch (const string& e) { noSuchName(); }
		catch (...) { cout << "Unknown error" << endl; }
	}
	return member;
}

FanPage* FacebookIO::getPageException()
{
	FanPage* page = nullptr;
	getchar();
	while (!page)
	{
		try
		{
			page = chooseFanPageFromList();
		}
		catch (const string& e) { noSuchName(); }
		catch (...) { cout << "Unknown error" << endl; }
	}
	return page;
}