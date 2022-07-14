

#ifndef __DATE_H_
#define __DATE_H_
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
using namespace std;


class Date
{
public:
	Date(); // Default Ctor
	Date(int d, int m, int y); // Ctor with values 
	~Date() {}; // Dtor
	Date(const Date& temp); // CCtor
	void PrintDate() const; // Prints the date;
	Date SubDate(const Date& temp) const; // Finds the difference between two dates (returns a Date object)
	int GetMonthDays(int month) const; // Returns the amount of days in the month (parameter)
	Date& operator=(const Date& temp); // operator =

private:
	int day;
	int month;
	int year;
};






#endif
