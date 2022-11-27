#include "Admin.h"

void Admin:: printMenu() 
{
	cout << "\n";
	cout << "Wellcome to facebook!" << endl;
	cout << "Please choose an action:" << endl;
	cout << "1 - create a memeber" << endl;
	cout << "2 - create a fan page" << endl;
	cout << "3 - add status to a fan page/member" << endl;
	cout << "4 - show all fan page/member statuses" << endl;
	cout << "5 - show 10 new statuses" << endl;
	cout << "6 - add a friend" << endl;
	cout << "7 - delete friendship" << endl;
	cout << "8 - add fan page" << endl;
	cout << "9 - delete fan page" << endl;
	cout << "10 - show all acounts and fan pages" << endl;
	cout << "11 - show all friends/fans of member" << endl;
	cout << "12 - exit" << endl;
	cout << "_______________________" << endl;
	cout << "\n";
}

void Admin:: menu()
{
	int action;

	do
	{
		printMenu();
		cin >> action;

		switch (action) {
		case 1:
			createMember();
			break;
		case 2:
			createFanPage();
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:
			users.printAllMembers();
			fanPages.printAllPages();
			break;
		case 11:

			break;
		}

	} while (action != 12);
}

void Admin:: createMember()
{
	Member* member = getDetailsForMember();
	users.addMember(member);
}

Member* Admin::getDetailsForMember()
{
	int day =0 , month =0, year=0;
	char slash_dummy;
	char name[20];

	do {
		cout << "Please enter a name - max 20 letters" << endl;
		cin.ignore();
		cin.getline(name, 20);
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
	fanPages.addPage(fanPage);
}

FanPage* Admin::getDetailsForPage()
{
	char name[20];

	do {
		cout << "Please enter the name  of the page- max 20 letters" << endl;
		cin.ignore();
		cin.getline(name, 20);
	} while (fanPages.checkIfNameExist(name));

	FanPage* fanPage = new FanPage(name);
	return fanPage;
}
