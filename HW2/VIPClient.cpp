

#include "VIPClient.h"


VIPClient::VIPClient(String name, String id, char gender, int age, char** hobbies, int Num_Of_Hobbies, int minimumHobbies): Client(name,id,gender,age,hobbies, Num_Of_Hobbies) // Ctor with values
{   // Using the Client's Ctor for all the parameters exept the one from the VIP class
	this->Min_IncomingHobbies = minimumHobbies; // Initializing thw parameter
}

VIPClient::~VIPClient() // Dtor
{

}

VIPClient::VIPClient(const VIPClient& temp):Client(temp) //CCtor
{   // Using the Client's CCtor for all the parameters exept the one from the VIP class
	this->Min_IncomingHobbies = temp.Min_IncomingHobbies;  // Initializing thw parameter from temp 
}

VIPClient& VIPClient::operator=(const VIPClient& temp)  // Operator = is initializing the object at the right (of the =) to the one on the left
{
	if (this != &temp) // Incase the strings of the objects are not the same
	{
		Client::operator=(temp); // Using the Clients operator =
		this->Min_IncomingHobbies = temp.Min_IncomingHobbies; // Initializing thw parameter from temp 
	}
	return *this; // Returning the object
}

bool VIPClient::operator==(const Client& temp) // Operator == checks if two Clients are a match (by the standard of age ,gender and common hobbies) 
{
	if (Client::operator==(temp)) // Incase the objects have at least one incoming hobbie
	{
		if (this->CommonInterests(*this, temp) >= this->Min_IncomingHobbies) // Incase the objects have the required amount of incoming hobbies
			return true; // Returns true if they do
		else
			return false; // Returns true if they don't
	}
	return false; // Incase the objects have no incoming hobbie
}
