#include "status.h"

status::status(char* text) // c'tor with text
{
	time_t curr_time;
	curr_time = time(NULL);
	date_and_time = ctime(&curr_time);
	this->text = text;
}

status::status() //default c'tor
{
	time_t curr_time;
	curr_time = time(NULL);
	date_and_time = ctime(&curr_time);
	this->text = nullptr;
}

status::~status() //d'tor
{
	delete[]text;
}

void status::printStatus()
{
	cout << date_and_time << text<<endl;
}
