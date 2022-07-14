
 
#include "MatchmakingAgency.h"


MatchmakingAgency::MatchmakingAgency() // Default Ctor
{
	this->DB = NULL; // Initializing the array to NULL
	this->Size_DB = 0; // Setting the size to 0
}

MatchmakingAgency::~MatchmakingAgency() // Dtor
{
	for (int i = 0; i < this->Size_DB; i++) // A loop that goes over all the Clients (size of the array)
	{
		delete DB[i]; // Deleting the Client
	}
	delete[] this->DB; // Deleting the array
}

int MatchmakingAgency::Matches(const String& id) const  // Prints all the matches of the Client with this ID (if exists)
{
	Client* temp = NULL; //This pointer will point to the required Client ( if exists )

	int MatchFound = 0; // A variable that will tell if the match were found or not

	for ( int i = 0; i < this->Size_DB; i++) // A loop that goes over all the Clients (size of the array)
	{
		if (this->DB[i][0].GetID() == id) // Checking if there is a Client with this ID
		{
			temp = &this->DB[i][0]; // Pointing to the Client with the required ID
		}
	}

	if (temp != NULL) // Incase the Client exists
	{
		for (int i = 0; i < this->Size_DB; i++) // A loop that goes over all the Clients (size of the array)
		{
			if (*temp == this->DB[i][0]) // Incase the current Client is a match
			{
				cout << this->DB[i][0]; // Printing the Client
				MatchFound++; // Adding 1
			}
		}
	}

	return MatchFound; // Returning the variable ( to know if a match found ) 
}

void MatchmakingAgency::operator+=( Client& temp) // Adds a new Client
{
	int size = this->Size_DB; // Getting the size of the array ( number of Clients )
	Client** tempArr = new Client * [size + 1]; // Allocating memory in the size of the current array + 1 for the new Client
	if (tempArr == NULL)  // Incase the allocation didn't succeed
	{
		cout << "Could not allocate memory. \n";
		exit(1);  // The program will stop
	}

	for (int i = 0; i < size; i++) // A loop that goes over all the array
		tempArr[i] = &this->DB[i][0]; // Puts every Client in the same place he was in the previous array

	delete this->DB; // Deletes the previous array

	tempArr[size] = &temp; // Puts the new Client at the new added place

	this->DB = tempArr; // The object's array points at the new array
	this->Size_DB++; // Increasing the size of the array by 1
}

void MatchmakingAgency::operator-=(Client& temp) // Removes a Client
{
	Client** tempArr = NULL; // Stting the temp array to NULL
	int index = this->Size_DB + 1; // Putting an index that not exists, to know if there is a reason to proceed in the second loop
	int size = this->Size_DB; // Getting the size of the array ( number of Clients )

	for (int i = 0; i < size; i++) // A loop that goes over all the array
	{
		if (this->DB[i][0].GetID() == temp.GetID()) // Checking if this client exists
		{
			index = i; // Getting his index in the array
		}
	}

	if (index != this->Size_DB + 1) // Incase the index is inside the array
	{
		Client** tempArr = new Client * [size - 1]; // Allocating memory in the size of the current array - 1 (because we are removing a Client)
		if (tempArr == NULL)  // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1);  // The program will stop
		}

		int i = 0; // Setting an i variable to 0

		while (i < index) // Moving at the array until the index's place
		{
			tempArr[i] = &this->DB[i][0]; // Puts every Client in the same place he was in the previous array ( until the index )
			i++; // increasing i by 1
		}

		delete this->DB[i]; // Deleting the required Client

		while (i < size - 1)// Moving at the array from the index's place until the end of the array
		{
			tempArr[i] = &this->DB[i + 1][0]; // Puts every Client in his index - 1 because we removed a Client
			i++; // increasing i by 1
		}

		delete[] this->DB; // 

		this->DB = tempArr;  // Deletes the previous array
		this->Size_DB--;  // Decreasing the size of the array by 1
	}
}

Client* MatchmakingAgency::GetClient(const String& id) const // Returns the Client with this ID (parameter)
{
	for (int i = 0; i < this->Size_DB; i++) // A loop that goes over all the Clients (size of the array)
	{
		if (this->DB[i][0].GetID() == id) // Checking if there is a Client with this ID
		{
			return &this->DB[i][0]; // Returning the Client's adress
		}
	}
	return NULL; // Returnig NULL if the Client with this ID Doesn't exists
}



/////////// Global Functions//////////////////

ostream& operator<<(ostream& os, const MatchmakingAgency& temp)  //Prints all the existing Clients in the DB array
{
	for (int i = 0; i < temp.Size_DB; i++) // A loop that goes over all the Clients (size of the temp array)
	{
		os << temp.DB[i][0]; // Printing the Client ( Has his own Printing operator )
	}
	return os;
}
