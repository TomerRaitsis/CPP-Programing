

#include "String.h"

String::String() // Default Ctor
{
	this->Str = NULL; // Setting the pointer to NULL
}

String::String(const char* temp) // A Ctor that Initialize the object's string with a string parameter (temp)  
{
	if (temp != NULL) // Incase the temp string is not NULL
	{
		int SizeOfString = strlen(temp); // Getting the length of the temp string

		this->Str = new char[SizeOfString + 1]; // Allocating memory in the size of temp ( +1 is for the '\0')
		if (this->Str == NULL) // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1); // The program will stop
		}

		strcpy(this->Str, temp); // Copying the temp string to the object's Str (after the allocation succeeded)
	}
}

String::~String() // Dtor
{
	delete[] this->Str; // Deleting the object's string
}

String::String(const String& temp) // CCtor
{
	if (temp.Str != NULL) // Incase temp string in not NULL
	{
		int SizeOfString = strlen(temp.Str); //  Getting the length of the temp's string

		this->Str = new char[SizeOfString + 1]; // Allocating memory in the size of temp ( +1 is for the '\0')
		if (this->Str == NULL) // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1); // The program will stop
		}

		strcpy(this->Str, temp.Str); // Copying temp's string to the object's Str (after the allocation succeeded)
	}
	else
		this->Str = NULL; // If temp's Str is NULL, The object's Str will be NULL too
}

String& String::operator=(const String& temp) // Operator = is initializing the object at the right (of the =) to the one on the left
{
	if (this != &temp && temp.Str != NULL) // Incase the strings of the objects are not the same and the temp's string is not NULL
	{
		int SizeOfString = strlen(temp.Str);  //  Getting the length of the temp's string
		if(this->Str != NULL) // Incase the object's string is not NULL 
			delete[] this->Str; // Deleting the object's string
		this->Str = new char[SizeOfString + 1]; // Allocating memory in the size of temp ( +1 is for the '\0')
		if (this->Str == NULL) // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1); // The program will stop
		}
		strcpy(this->Str, temp.Str);// Copying temp's string to the object's Str (after the allocation succeeded)
	}
	return *this; // Returning the object
}

bool String::operator==(const String& temp) const // Operator == checks if two strings are equal
{

	if (strcmp(this->Str, temp.Str)) // The strcmp returns 0 if the strings are equal or a number if they are different
		return false; // Returns false if the string are different
	return true; // Returns true if they are equal 

}

String& String::operator+(const String& temp) // Operator + combines two string together
{
	String t = this->Str; // Initializing the string of the object to a temp object (t)

	delete[] this->Str; // Deleting the object's string

	this->Str = new char[strlen(t.Str) + strlen(temp.Str) + 3]; // Allocating memory in the size of the two string and a space between them and a '\0'
	if (this->Str == NULL)// Incase the allocation didn't succeed
	{
		cout << "Could not allocate memory. \n";
		exit(1);// The program will stop
	}

	for (int i = 0; i < strlen(t.Str) + strlen(temp.Str) + 3; i++) // This loop is zeroing the new string
	{
		this->Str[i] = '\0'; 
	}
	

	for (int i = 0; i < strlen(t.Str); i++) //This loop is copying the t string 
	{
		this->Str[i] = t.Str[i];
	}
	this->Str[strlen(t.Str)] = '  '; // Adding a space between the words
	int j = strlen(t.Str) + 1;
	for (int i = 0; i < strlen(temp.Str); i++)  // This loop is copying the temp's string 
	{
		this->Str[j] = temp.Str[i];
		j++;
	}
	this->Str[strlen(t.Str) + strlen(temp.Str) + 2] = '\0'; // Adding a '\0' to the end of the string

	return *this; // returning the object
}



////////    Global functions  //////// 

ostream& operator<<(ostream& os, const String& temp) // Operator << is printing the object
{
	return os << temp.Str<< endl; // Prints the string
}
