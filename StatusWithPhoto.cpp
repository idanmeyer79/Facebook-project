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

void StatusWithPhoto::printStatus() const
{
	Status::printStatus();
	cout << "this is printed in " << statusColor << endl;
	system("start yosi.jpeg");
}

void StatusWithPhoto::saveToFile(std::ofstream& outFile) const
{
	outFile << typeid(*this).name() + 6 << endl;
	outFile << date_and_time;
	outFile << text << endl;
	outFile << statusColor << endl;
}

std::ostream& operator<< (std::ostream& out, const StatusWithPhoto& status) {
	out << status.text << " - " << status.statusColor <<" - " << status.date_and_time;
	return out;
}