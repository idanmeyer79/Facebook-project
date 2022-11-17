#include "status.h"

status::status(char* text)
{
	time_t curr_time;
	curr_time = time(NULL);
	date_and_time = ctime(&curr_time);
	this->text = text;
}

status::status()
{
	time_t curr_time;
	curr_time = time(NULL);
	date_and_time = ctime(&curr_time);
	this->text = nullptr;
}

void status::printStatus()
{
	cout << date_and_time << endl << text;
}
