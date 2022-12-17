#include "Status.h"
using namespace std;

//Status::Status(const string t) // c'tor with text
//{
//	text = t;
//	time_t curr_time;
//	curr_time = time(NULL);
//	string tm = ctime(&curr_time);
//	this->date_and_time = tm;
//}

Status::Status(string t) // c'tor with text
{
	text = t;
	time_t curr_time;
	curr_time = time(NULL);
	string tm = ctime(&curr_time);
	this->date_and_time = tm;
}

//Status::~Status() //d'tor
//{
//	delete[]text;
//	delete[]date_and_time;
//}

void Status::printStatus()
{
	cout << "The status created at: " << date_and_time << "The status is: " << text << endl;
}

bool Status:: setText(const string text)
{
	this->text = text;
	return true;
}

bool Status:: operator==(Status& other)
{
	return text == other.getText() ? true : false;
}

bool Status::  operator!=(Status& other)
{
	return text != other.getText() ? true : false;
}

