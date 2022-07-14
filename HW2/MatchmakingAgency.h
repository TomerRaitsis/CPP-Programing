

#ifndef __MATCHMAKINGAGENCY_H__
#define __MATCHMAKINGAGENCY_H__
#include"VIPClient.h"

class MatchmakingAgency
{
public:
	MatchmakingAgency(); // Default Ctor
	~MatchmakingAgency(); // Dtor
	int Matches(const String& id) const; // Prints all the matches of the Client with this ID (if exists)
	Client* GetClient(const String& id) const; // Returns the Client with this ID (parameter)
	friend ostream& operator<<(ostream& os, const MatchmakingAgency& temp); //Prints all the existing Clients in the DB array
	void operator+=(Client& temp); // Adds a new Client
	void operator-=(Client& temp); // Removes a Client

private:
	Client** DB;
	int Size_DB;
};


#endif