#ifndef __STATUS_H__
#define __STATUS_H__
#include <ctime>
#include<iostream>
#pragma warning(disable: 4996)

class Status
{
private:
	std::string text;
	std::string date_and_time;

public:
	/**
	 * Constructs a new status with the given text.
	 *
	 * @param text The text of the status.
	 */
	Status(const std::string text);

	/**
	 * Sets the text of the status.
	 *
	 * @param text The new text of the status.
	 * @return `true` if the text was set successfully, `false` otherwise.
	 */
	bool setText(const std::string text);

	/**
	 * Returns the text of the status.
	 *
	 * @return The text of the status.
	 */
	std::string getText() { return text; }

	/**
	 * Returns the date and time at which the status was created.
	 *
	 * @return The date and time at which the status was created.
	 */
	std::string getDateAndTime() { return date_and_time; }

	/**
	 * Shows the status.
	 */
	void printStatus() const;

	/**
	 * Compares this status to another status based on their text.
	 *
	 * @param other The other status to compare to.
	 * @return `true` if the statuses have the same text, `false` otherwise.
	 */
	bool operator==(Status& other);

	/**
	 * Compares this status to another status based on their text.
	 *
	 * @param other The other status to compare to.
	 * @return `true` if the statuses have different text, `false` otherwise.
	 */
	bool operator!=(Status& other);
};

#endif // !__STATUS_H__



