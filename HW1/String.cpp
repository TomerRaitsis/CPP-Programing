

#include"String.h"

String::String() //Default Ctor
{
	str = NULL; // Points to NULL
}


int String::StringLength(const char* str) const 
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) // Counts the chars of the string
	{
		count++; // Adding 1 each rotation
	}

	return count; // Returns the amount of chars
}


String::String(const char* temp)
{
	int SizeOfString = StringLength(temp); // Gets the length of the string

	this->str = new char[SizeOfString + 1]; // Allocation of memory
	if (this->str == NULL) // Checks of succesful allocation
	{
		cout << "Could not allocate memory" << endl;
		exit(1); //Finishing the program incase of unsuccesful allocation
	}

	for (int i = 0; i < SizeOfString; i++) //Copying the string
	{
		this->str[i] = temp[i];
	}
	this->str[SizeOfString] = '\0';
}


String::String(const String& temp)
{
	int SizeOfString = StringLength(temp.str); // Getting the string length

	str = new char[SizeOfString + 1]; // allocating memory
	if (str == NULL) //checks if allocation is succesful
	{
		cout << "Could not allocate memory" << endl;
		exit(1); // Finishing the program if its unsuccesful
	}

	for (int i = 0; i < SizeOfString; i++) // Copying the string
	{
		str[i] = temp.str[i];
	}
	str[SizeOfString] = '\0';
}


String::~String() // Dtor
{
	delete[] str; //Deletes the string
}


void String::PrintString() const
{
	if (this->str == NULL) // Incase it points to NULL
		cout << "The String points to NULL" << endl;
	else
	{
		cout << this->str << endl; //Prints the string
	}
}


void String::UpdateString(const String& temp)
{
	if (this->str != temp.str)
	{
		int SizeOfString = StringLength(temp.str); // Gets the length of the string

		delete[] this->str; // Deletes the previous string

		this->str = new char[SizeOfString + 1]; // Allocating memory
		if (this->str == NULL) // Checks if allocations was seccesful
		{
			cout << "Could not allocate memory" << endl;
			exit(1); //Finishing the program ifits unsucceful
		}

		for (int i = 0; i < SizeOfString; i++) // Copying the string
		{
			this->str[i] = temp.str[i];
		}

		this->str[SizeOfString] = '\0';
	}
}


String& String::operator=(const String& temp)
{
	if (this != &temp) // Checks if they are pointing to the same adress
	{
		int SizeOfString = StringLength(temp.str); // Gets strings length

		if (this->str != NULL) // If there is data at this adress
			delete[] this->str; // Deletes the string

		this->str = new char[SizeOfString + 1]; // allocates memory
		if (this->str == NULL) // checks if the allocation was succesful
		{
			cout << "Could not allocate memory";
			exit(1); // Finishing the program if the allocation was not succesful
		}

		for (int i = 0; i < SizeOfString; i++) // copying the string
		{
			this->str[i] = temp.str[i];
		}
		this->str[SizeOfString] = '\0';
	}
	
	return *this; // return the value 

}

