#include "Status.h"
using namespace std;

Status::Status(const string t) // c'tor with text
{
	text = t;
	time_t curr_time;
	curr_time = time(NULL);
	this->date_and_time = ctime(&curr_time);
}

void Status::printStatus() const
{
	cout << "The status created at: " << date_and_time << "    The status is: " << text << endl;
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



std::ostream& operator<< (std::ostream& out, const Status& status) {
	out << status.text << " - " << status.date_and_time;
	return out;
}
