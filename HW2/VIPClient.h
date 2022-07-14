

#ifndef __VIPCLIENT_H__
#define __VIPCLIENT_H__
#include"Client.h"

class VIPClient : public Client //This class inherits from the Client class
{
public:
	VIPClient(String name, String id, char gender, int age, char** hobbies, int Num_Of_Hobbies, int minimumHobbies ); // Ctor with values
	~VIPClient(); // Dtor
	VIPClient(const VIPClient& temp); // CCtor
	VIPClient& operator=(const VIPClient& temp); // Operator =
	bool operator==(const Client& temp); // Compairing operator

private:
	int Min_IncomingHobbies;
};

#endif