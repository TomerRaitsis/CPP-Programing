

#include"ShoppingCart.h"
#include"Shop.h"


#ifndef __DATABASE_H_
#define __DATABASE_H_

class DataBase
{
public:
	DataBase(); // Ctor
	~DataBase(); // Dtor
	void PrintMenu1() const; // Menu 1
	void PrintMenu2() const; // Menu 2
	void PrintMenu3() const; // Menu 3
	int SerialExists(int s) const; // Checking if the parameter serial exists
	void AddNewBusket(ShoppingCart& temp); // Adding a new item to the busket


private:
	Shop S;
	ShoppingCart* SC;
	int Scsize;
};


#endif
