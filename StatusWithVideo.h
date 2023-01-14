#ifndef __STASUS_WITH_VIDEO_H__
#define __STASUS_WITH_VIDEO_H__
#include <iostream>
#pragma warning(disable: 4996)
#include "status.h"

class StatusWithVideo : public Status
{
private:
	std::string statusColor;
public:
	/**
	@brief Constructs a StatusWithVideo object by loading data from a file.
	@param file The input file stream to read the data from.
	*/
	StatusWithVideo(std::ifstream& file);

	/**
	@brief Constructs a StatusWithVideo object with the given text and color.
	@param text The text of the status.
	@param color The color of the status.
	*/
	StatusWithVideo(std::string text, std::string color);
	
	/**
	@brief Copy constructor for StatusWithVideo objects.
	@param other The StatusWithVideo object to be copied.
	*/
	StatusWithVideo(const StatusWithVideo& other);
	
	/**
	@brief Prints the text and color of the status to the console.
	*/
	virtual void printStatus() const override;
	
	/**
	@brief Overloads the << operator for outputting StatusWithVideo objects.
	@param out The output stream.
	@param status The StatusWithVideo object to be outputted.
	@return The output stream.
	*/
	friend std::ostream& operator<< (std::ostream& out, const StatusWithVideo& status);
	
	/**
	@brief Saves the StatusWithVideo object to a file.
	@param outFile The output file stream to save the StatusWithVideo object to.
	*/
	virtual void saveToFile(std::ofstream& outFile) const override;
};

#endif //!__STASUS_WITH_VIDEO_H__