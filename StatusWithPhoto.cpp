#include "StatusWithPhoto.h"
#include <fstream>
#include <string>
using namespace std;

StatusWithPhoto::StatusWithPhoto(std::ifstream& file):Status(file)
{
	getline(file, statusColor);
}

StatusWithPhoto::StatusWithPhoto(string text, string color) :Status(text)
{
	statusColor = color;
}

StatusWithPhoto::StatusWithPhoto(const StatusWithPhoto& other): Status(other)
{
	statusColor = other.statusColor;
}

void StatusWithPhoto::printStatus() const
{
	Status::printStatus();
	cout << "    this is a StatusWithPhoto with text printed in " << statusColor << endl;
	system("start yosi.jpeg");
}

void StatusWithPhoto::saveToFile(std::ofstream& outFile) const
{
	outFile << typeid(*this).name() + SKIP_CLASS << endl;
	outFile << date_and_time;
	outFile << text << endl;
	outFile << statusColor << endl;
}

std::ostream& operator<< (std::ostream& out, const StatusWithPhoto& status)
{
	out << status.text << " - " << status.statusColor <<" - " << status.date_and_time;
	return out;
}