

#include "Client.h"


Client::Client() // Default Ctor
{
	this->Name = "123"; // puts a number instead of name
	this->ID = "123"; // short number for an ID
	this->Gender = '\0'; // '\0' for a gender
	this->Age = 0; // 0 for age
	this->Hobbies = NULL; // No hobbies
	this->NumOfHobbies = 0;
	// There is not going to be a use in these values (this is going to be for creating a Client without a CCtor), but it is still needed
}

Client::Client(String name, String id, char gender, int age, char** hobbies, int Num_Of_Hobbies):Name(name),ID(id) //Ctor with values
{   // Name and ID are created with thier own Ctor
	this->Gender = gender; // Initializing the gender
	if (age > Minimum_Age && age < Maximum_Age) // Checking if the age is vallid (between 18-120) 
		this->Age = age; // Initializing the age 
	else
		this->Age = DefaultAge; // Initializing the age to the default value (35)
	
	this->NumOfHobbies = Num_Of_Hobbies; //Initializing the number of hobbies
	this->Hobbies = new char* [Num_Of_Hobbies]; // Allocating memory 
	if (this->Hobbies == NULL)// Incase the allocation didn't succeed
	{
		cout << "Could not allocate memory. \n";
		exit(1); // The program will stop
	}
	for (int i = 0; i < Num_Of_Hobbies; i++) // A loop that goes over all the hobbies
	{
		this->Hobbies[i] = new char[strlen(hobbies[i]) + 1]; // Allocating memory in the size of the hobbie ( +1 is for the '\0')
		if (this->Hobbies[i] == NULL) // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1); // The program will stop
		}
		strcpy(this->Hobbies[i], hobbies[i]); // Copying the hobbie parameter to its place in the hobbies array
	}
}

Client::~Client() // Dtor
{
	for ( int i = 0; i < this->NumOfHobbies ; i++) //A loop that goes over all the hobbies
	{
		delete[] this->Hobbies[i]; // Deleting the hobbie at the current place
	}
	delete[] this->Hobbies; // deleting the whole array
}

Client::Client(const Client& temp):Name(temp.Name),ID(temp.ID) // CCtor
{   // Name and ID are created with thier own CCtor
	this->Gender = temp.Gender;  // Initializing the gender
	this->Age = temp.Age; // Initializing the age 
	this->NumOfHobbies = temp.NumOfHobbies; // Initializing the number of hobbies
	this->Hobbies = new char* [temp.NumOfHobbies]; // Allocating memory 
	if (this->Hobbies == NULL)// Incase the allocation didn't succeed
	{
		cout << "Could not allocate memory. \n";
		exit(1); // The program will stop
	} 
	for (int i = 0; i < temp.NumOfHobbies; i++) // Allocating the memory for the hobbies and copying them to their places
	{
		this->Hobbies[i] = new char[strlen(temp.Hobbies[i]) + 1]; // Allocating memory in the size of the hobbie ( +1 is for the '\0')
		if (this->Hobbies[i] == NULL) // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1); // The program will stop
		}
		strcpy(this->Hobbies[i], temp.Hobbies[i]); // Copying the hobbie parameter to its place in the hobbies array
	}
}

bool Client::operator==(const Client& temp) // Operator == checks if two Clients are a match (by the standard of age ,gender and common hobbies) 
{
	if (this->Gender != temp.Gender) // The gender need to be different ( male and a female)
	{
		if ((this->Age - temp.Age <= 5) && (temp.Age - this->Age <= 5)) // Max age difference allowed is 5 years 
		{
			if (CommonInterests(*this, temp)) // Checking if they have a common hobbie
				return true; // Returning true if the do
		}
	}
	return false; // Returning false if the Clients are not a match
}

int Client::CommonInterests(const Client& temp1, const Client& temp2) const // Function that checks if there are common interests (hobbies) between two Client objects
{
	int count = 0; // A variable to count the number of common interests

	if (temp1.NumOfHobbies >= temp2.NumOfHobbies) // Incase temp1 has more hobbies than temp2
	{
		for (int i = 0; i < temp1.NumOfHobbies; i++) // A loop that goes over all the hobbies of temp1
		{
			for (int j = 0; j < temp2.NumOfHobbies; j++) // A loop that goes over all the hobbies of temp2
			{
				if (strcmp(temp1.Hobbies[i], temp2.Hobbies[j]) == 0) // If the two hobbies are the same
					count++; // Adding 1 to count
			}
		}
	}
	else   // Incase temp2 has more hobbies than temp1
	{
		for (int i = 0; i < temp2.NumOfHobbies; i++) // A loop that goes over all the hobbies of temp2
		{
			for (int j = 0; j < temp1.NumOfHobbies; j++) // A loop that goes over all the hobbies of temp1
			{
				if (strcmp(temp2.Hobbies[i], temp1.Hobbies[j]) == 0) // If the two hobbies are the same
					count++; // Adding 1 to count
			}
		}

	}
	return count; // Returning the count (number of common interests)
}

String& Client::GetID() // Function that returns the ID String
{
	return this->ID; // Returning the ID String object
}

Client& Client::operator=(const Client& temp) // Operator = is initializing the object at the right (of the =) to the one on the left
{
	if (this != &temp) // Incase the strings of the objects are not the same
	{
		this->Name = temp.Name; // Initializing the name
		this->ID = temp.ID; // Initializing the ID
		this->Gender = temp.Gender;  // Initializing the gender
		this->Age = temp.Age;  // Initializing the age

		if (this->Hobbies != NULL) // Incase the hobbies array is not empty
		{
			for (int i = 0; i < this->NumOfHobbies; i++) // A loop that goes over all the hobbies
			{
				delete[] Hobbies[i]; // Deletes the hobbie at the current place
			}
			delete[] Hobbies; // Deletes the whole array
		}
			this->NumOfHobbies = temp.NumOfHobbies; // Initializing the number of hobbies of the temp Client
			this->Hobbies = new char* [this->NumOfHobbies]; // Allocating memory
			if (this->Hobbies == NULL) // Incase the allocation didn't succeed
			{
				cout << "Could not allocate memory. \n";
				exit(1); // The program will stop
			}
			for (int i = 0; i < this->NumOfHobbies; i++)
			{
				this->Hobbies[i] = new char[strlen(temp.Hobbies[i]) + 1]; // Allocating memory in the size of the hobbie ( +1 is for the '\0')
				if (this->Hobbies[i] == NULL) // Incase the allocation didn't succeed
				{
					cout << "Could not allocate memory. \n";
					exit(1); // The program will stop
				}
				strcpy(this->Hobbies[i], temp.Hobbies[i]); // Copying the hobbie parameter to its place in the hobbies array
			}
	}
	return *this; // Returning the object
}



////////    Global functions  //////// 

ostream& operator<<(ostream& os, const Client& temp) // A function that prints all the Clients data
{
	os << "Name: " << temp.Name << "ID: " << temp.ID; // Printing the Name and ID
	os << "Age: " << temp.Age << endl; // Printing the age
	os << "Gender: "; // Printing the gender
	if (temp.Gender == 'f' || temp.Gender == 'F') // Incase it is a female
		os << "Female" << endl;
	else // Incase it is a male
		os << "Male" << endl;
	os << "Hobbies: " << endl;
	for (int i = 0; i < temp.NumOfHobbies; i++) // A loop that goes over all the hobbies
	{
		os << temp.Hobbies[i] << endl; // Printing the hobbie 
	}
	return os;

}




