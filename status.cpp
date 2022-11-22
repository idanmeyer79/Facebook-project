#include "Status.h"

Status::Status(char* text) // c'tor with text
{
	time_t curr_time;
	curr_time = time(NULL);
	date_and_time = ctime(&curr_time);
	this->text = text;
}

Status::~Status() //d'tor
{
	delete[]text;
}

void Status::printStatus()
{
	cout << date_and_time << text<<endl;
}
