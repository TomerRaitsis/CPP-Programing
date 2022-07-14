

#ifndef __MENU_H__
#define __MENU_H__
#include"MatchmakingAgency.h"


class Menu
{
public:
	Menu(); // A Ctor that also manages the rest of the function

private:
	MatchmakingAgency M;
	void AddNew(); // Adds new Client
	void Remove(); // Removes a Client
	void Print(); // Prints all the existing clients 
	void FintMatch(); // Finds all the matches for a Client
	void PrintMenu(); // Prints the menu for the user 
};


#endif