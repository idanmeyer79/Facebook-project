#include "StatusWithVideo.h"
#include <fstream>
#include<string>
using namespace std;

StatusWithVideo::StatusWithVideo(std::ifstream& file):Status(file)
{
	getline(file, statusColor);
}

StatusWithVideo::StatusWithVideo(std::string text, std::string color) :Status(text)
{
	statusColor = color;
}

StatusWithVideo::StatusWithVideo(const StatusWithVideo& other) :Status(other)
{
	statusColor = other.statusColor;
}

void StatusWithVideo::printStatus() const
{
	Status::printStatus();
	cout << "    this is a StatusWithVideo with text printed in " << statusColor << endl;
	system("start stam.mp4");
}

void StatusWithVideo::saveToFile(std::ofstream& outFile) const
{
	outFile << typeid(*this).name() + SKIP_CLASS << endl;
	outFile << date_and_time;
	outFile << text << endl;
	outFile << statusColor << endl;
}

std::ostream& operator<< (std::ostream& out, const StatusWithVideo& status)
{
	out << status.text << " - " << status.statusColor << " - " << status.date_and_time;
	return out;
}