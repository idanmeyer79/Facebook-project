#include "StatusWithVideo.h"
using namespace std;


StatusWithVideo::StatusWithVideo(std::string text, std::string color) :Status(text)
{
	statusColor = color;
}

void StatusWithVideo::printStatus() const
{
	Status::printStatus();
	cout << "    this is printed in " << statusColor << endl;
	system("start stam.mp4");
}
