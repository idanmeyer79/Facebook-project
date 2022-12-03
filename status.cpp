#include "Status.h"
using namespace std;

Status::Status(const char* t) // c'tor with text
{
	text = new char[strlen(t) + 1];
	strcpy(text, t);

	time_t curr_time;
	curr_time = time(NULL);
	char* tm = ctime(&curr_time);
	this->date_and_time = new char[strlen(tm) + 1];
	strcpy(date_and_time, tm);
}

Status::Status(char* t)
{
	text = new char[strlen(t) + 1];
	strcpy(text, t);

	time_t curr_time;
	curr_time = time(NULL);
	char* tm = ctime(&curr_time);
	this->date_and_time = new char[strlen(tm) + 1];
	strcpy(date_and_time, tm);
}


Status::~Status() //d'tor
{
	delete[]text;
}

void Status::printStatus()
{
	cout << "The status created at: " << date_and_time << "The status is: " << text << endl;
}
