

#include "Menu.h"

#define AddClient 1
#define RemoveClient 2
#define PrintClient 3
#define FindMatch 4
#define Exit 5

#define MaxFullNameLentgh 50
#define MaxFirstNameLentgh 24
#define MaxLastNameLentgh 24
#define MaxIDLength 9
#define MaxHobbieNameLentgh 50


Menu::Menu() // A Ctor that also manages the rest of the function
{

	int choice; // A variable for the user's choice
	bool run = true; // As long run = true the program will run 
	while (run)
	{
		PrintMenu(); // Prints the menu for the user 
		cin >> choice; // Gets the user's choice
		switch (choice) // Goes to a case according to the user's choice
		{
		case AddClient:
			AddNew(); // Adding a new client to the data base
			cout << endl;
			break; // Getting out of the switch menu after the case is done
		case RemoveClient:
			Remove(); // Removes a Client from the data base (needs the Clients ID) 
			cout << endl;
			break; // Getting out of the switch menu after the case is done
		case PrintClient: 
			Print(); // Prints all the existing clients 
			cout << endl;
			break; // Getting out of the switch menu after the case is done
		case FindMatch:
			this->FintMatch(); // Finds all the matches for a Client (needs the Clients ID) 
			cout << endl;
			break; // Getting out of the switch menu after the case is done
		case Exit:
			run = false; // Gets out of the while ( that means the program is finished by the user's choice )
			cout << "GoodBye" << endl;
			break; // Getting out of the switch menu after the case is done
		default:  cout << "Wrong option. Please try again!\n";
		}
	}
}

void Menu::AddNew()
{
	char fname[MaxFirstNameLentgh] = "\0"; // Firstname variable
	char lname[MaxLastNameLentgh] = "\0"; // Lastname variable
	char ID1[MaxIDLength + 1] = "\0"; // ID variable
	char Gender; // Gender variable
	int Age; // Age variable
	char** Hobbies = NULL; // Hobbies array
	int NumOfHobbies; // Number of hobbies variable
	int Min_IncomingHobbies; // Number of incoming hobbies variable
	int Vip; // VIP variable
	char HobbiesName[MaxHobbieNameLentgh] = "\0"; // Temp variable for the hobbie's name

	cout << "Please enter your full name: " << endl;
	cout << "First name: ";
	cin >> fname; // initializing the firstname
	cout << "Last name: ";
	cin >> lname; // initializing the lastname

	String Fname = fname; // converting to a String object
	String Lname = lname; // converting to a String object
	String name = Fname + Lname; // Unitning the first and last name to a full name

	do
	{
		cout << "Please enter a valid ID number (9 digits): ";
		cin >> ID1; // initializing the ID
	} while (strlen(ID1) != MaxIDLength); // The ID must be on the right size or you will be asked again

	do
	{
		cout << "Please enter your gender ( M for Male or F for female): " << endl;
		cin >> Gender; // initializing the gender
	} while (Gender != 'm' && Gender != 'M' && Gender != 'f' && Gender != 'F'); // The gender must be as requaired or you will be asked again


	cout << "Please enter you age: " << endl;
	cin >> Age; // initializing the age

	cout << "Please enter the amount of your hobbies: " << endl;
	cin >> NumOfHobbies; // initializing the number of hobbies

	Hobbies = new char* [NumOfHobbies]; // Allocating memory 
	if (Hobbies == NULL)  // Incase the allocation didn't succeed
	{
		cout << "Could not allocate memory. \n";
		exit(1); // The program will stop
	}

	for (int i = 0; i < NumOfHobbies; i++) // A loop that goes over all the hobbies
	{
		cout << "Please enter hobbie number "<< i + 1 << " :" << endl;
		cin >> HobbiesName; // initializing the Hobbie's Name
		Hobbies[i] = new char[strlen(HobbiesName) + 1]; // Allocating memory in the size of teh hobbie's name ( +1 is for the '\0')
		if (Hobbies[i] == NULL)  // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1); // The program will stop
		}
		strcpy(Hobbies[i], HobbiesName); // Copying the hobbie to it's place in the array (after the allocation succeeded)
	}

	do
	{
		cout << "Is this a VIP Client? (1 for yes, 0 for no) " << endl;
		cin >> Vip; // initializing the VIP variable
	} while (Vip != 0 && Vip != 1); // Has to be 0 or 1, you will be asked again incase it is not

	if (Vip) // If the Client is VIP
	{
		do
		{
			cout << "What is the minimum amount of incoming hibbies? " << endl;
			cin >> Min_IncomingHobbies; // initializing the minimum incoming hobbies
		} while (Min_IncomingHobbies > NumOfHobbies); // Can not be bigger than the total of hobbies, you will be asked again if it is

		Client* New = new VIPClient(name, ID1, Gender, Age, Hobbies, NumOfHobbies, Min_IncomingHobbies); //Creating a VIPClient (dynamically allocatad)
		if (New == NULL) // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1);  // The program will stop
		}
		this->M += *New; // Adding the Client to the data base
	}
	else // If the Client is not VIP
	{
		Client* New = new Client(name, ID1, Gender, Age, Hobbies, NumOfHobbies); //Creating a Client (dynamically allocatad)
		if (New == NULL) // Incase the allocation didn't succeed
		{
			cout << "Could not allocate memory. \n";
			exit(1); // The program will stop
		}
		this->M += *New; // Adding the Client to the data base
	}

}

void Menu::Remove() // Removes a Client
{
	char ID[MaxIDLength + 1];
	cout << "Please enter the 9 digit ID of the client you wish to remove: " << endl;
	cin >> ID; // initializing the ID

	Client* ToRemove = this->M.GetClient(ID); // Getting the Client by his ID
	if (ToRemove == NULL) // Incase The Client Does not exists
	{
		cout << "There is no client with this ID! " << endl;
	}
	else
		this->M -= *ToRemove; // Removing the Client from the data base
	
}

void Menu::Print() 
{
	cout << this->M; // Prints all the existing clients 
}

void Menu::FintMatch() // Finds all the matches for a Client
{
	char ID[MaxIDLength + 1];
	cout << "Please enter the 9 digit ID of the client you wish to find his matches: " << endl;
	cin >> ID;  // initializing the ID

	cout << "Match: " << endl;
	if (this->M.Matches(ID) == 0) // Checks if there are matches and prints them
	{
		cout << "No matches found" << endl; // If there are no matches
	}
}

void Menu::PrintMenu() // Prints this menu for the user 
{
	cout << "Please choose one of the following options:  " << endl << endl;
	cout << "=================================================================" << endl;
	cout << "1) Add a new client  to the database." << endl;
	cout << "2) Remove an existing client from the database." << endl;
	cout << "3) Print all clients." << endl;
	cout << "4) Print all matches for a client." << endl;
	cout << "5) Quit the program." << endl;
	cout << "==================================================================" << endl;
}
