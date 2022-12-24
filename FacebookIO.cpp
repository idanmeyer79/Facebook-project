#include "FacebookIO.h"
#include"member.h"
#include <iostream>
using namespace std;

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

	do
	{
		cout << "Please enter a name - max 20 letters" << endl;
		getline(std::cin, name);
		if (admin->checkIfUserNameExist(name))
			nameAlreadyTaken();
		else
			validName = true;
	} while (!validName);


	while (true)
	{
		cout << "Please enter date of birth - format dd/mm/yyyy" << endl;
		cin >> day >> slash_dummy >> month >> slash_dummy >> year;
		try
		{
			Date date(day, month, year);
			cout << name << "\033[32m was created :)\033[0m" << endl;
			Member member(name, date);
			return member;
		}

		catch (const std::invalid_argument& e) {std::cout << "Error: " << e.what() << std::endl;}
		catch (const std::exception& e) {std::cout << "Error: " << e.what() << std::endl;}
		catch (...) {std::cout << "Unknown error" << std::endl;}
	}
}

FanPage FacebookIO::getDetailsForPage() 
{
	string name;
	bool validName = false;
	getchar(); //clear the buffer 

	do
	{
		cout << "Please enter a name - max 20 letters" << endl;
		getline(std::cin, name);
		if (admin->checkIfPageNameExist(name))
			nameAlreadyTaken();
		else
			validName = true;
	} while (!validName);

	FanPage fanPage(name);
	cout << name << "\033[32m was created :)\033[0m" << endl;
	return fanPage;
}

Status FacebookIO::getStatusFromUser()
{
	string text;
	displayMessage("Please enter a new status: ");
	text=getUserInput();
	Status status(text);
	return status;
}

int FacebookIO::selectMemberOrPage()
{
	int selector;
	displayMessage("For a member enter 1, For a Fan page enter 2");
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
	{
		cout << "#" << ++i << " " << (*itr).getName() << endl;
	}
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
	{
		cout << "#" << ++i << " " << (*itr).getName() << endl;
	}
}

void FacebookIO::printAllMemberStatuses(const Member& member) const
{
	member.printAllStatuses();
}

void FacebookIO::printAllPageStatuses(const FanPage& page) const
{
	page.printAllStatuses();
}
