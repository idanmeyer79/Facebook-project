#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	int action;

	do
	{
		cout << "Wellcome to facebook!" << endl;
		cout << "Please choose an action:" << endl;
		cout << "1 - create an acount" << endl;
		cout << "2 - create a fan page" << endl;
		cout << "3 - add status to a fan page/member" << endl;
		cout << "4 - show all fan page/member statuses" << endl;
		cout << "5 - show 10 new statuses" << endl;
		cout << "6 - add a friend" << endl;
		cout << "7 - delete friendship" << endl;
		cout << "8 - add fan page" << endl;
		cout << "9 - delete fan page" << endl;
		cout << "10 - show all acounts and fan pages" << endl;
		cout << "11 - show all friends/fans" << endl;
		cout << "12 - exit" << endl;
		cin >> action;

		switch (action) {
		case 1:
			createMember();
			break;
		case 2:

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

			break;
		case 11:

			break;
		}


	} while (action != 12);
}

void createMember()
{
	Date date;
	char* name = new char[20];

	cout << "Please enter a name - max 20 letters" << endl;
	cin >> name;
	cout << "Please enter date of birth" << endl;
	cin >> date;

	
}
