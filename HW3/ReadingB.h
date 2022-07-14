

#include"Books.h"

#ifndef __READINGB_H_
#define __READINGB_H_


class ReadingB : public Books
{
public:
	ReadingB(char* name, int serial, int publishyear, float price, int numofpages, char* genre); // Ctor
	~ReadingB(); // Dtor
	ReadingB(const ReadingB& temp); // CCtor
	ReadingB& operator=(const ReadingB& temp);// Operator =
	 virtual bool operator==(const ReadingB& temp) const; // Operator ==
	ostream& Print(ostream& os) const; // Print function
	friend ostream& operator<<(ostream& os, const ReadingB& temp); // Print operator <<


private:
	char* Genre;
};


#endif
