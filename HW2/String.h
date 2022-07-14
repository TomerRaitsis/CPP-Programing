

#ifndef __STRING_H_
#define __STRING_H_

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class String
{
public:
	String(); //Default Ctor
	String(const char* temp); // Ctor with values
	~String(); // Dtor
	String(const String& temp); // CCtor
	String& operator=(const String& temp) ; // Operator =
	bool operator==(const String& temp) const; // Compairing operator
	friend ostream& operator<<(ostream& os, const String& temp);// Printing operator 
	String& operator+(const String& temp); // Operator for combining two String objects

private:
	char* Str;
};

#endif