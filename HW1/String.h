

#ifndef __STRING_H_
#define __STRING_H_
#include<iostream>
using namespace std;


class String
{
public:
	String(); //Default Ctor
	String(const char* temp); //Ctor with values
	~String(); // Dtor
	String(const String& temp); // CCtor
	int StringLength(const char* str) const; //Returns the length of the string
	void PrintString() const; // prints the string
	void UpdateString(const String& temp); // Updates the string
	String& operator=(const String& temp); // operator =
	

private:
	char* str;
};


#endif
