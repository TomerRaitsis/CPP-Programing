

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include"String.h"
#define Minimum_Age 18
#define Maximum_Age 120
#define DefaultAge 35

class Client
{
public:
	Client(); //Default Ctor
	Client(String name, String id, char gender, int age, char** Hobbies, int NumOfHobbies); //Ctor with values
	~Client(); // Dtor
	Client(const Client& temp); // CCtor
	Client& operator=(const Client& temp); // Operator =
	virtual bool operator==(const Client& temp); // Compairing operator
	friend ostream& operator<<(ostream& os, const Client& temp); // Printing operator 
	int CommonInterests(const Client& temp1, const Client& temp2) const; // Function that checks if there are common interests (hobbies) between two Client objects
	String& GetID(); // Function that returns the ID String

private:
	String Name;
	String ID;
	char Gender;
	int Age;
	char** Hobbies;
	int NumOfHobbies;
};

#endif