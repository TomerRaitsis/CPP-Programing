

#include"Product.h"
#define MoviePrice 20

#ifndef __ACTIONM_H_
#define __ACTIONM_H_


class ActionM : virtual public Product
{
public:
	ActionM(char* name, int serial, int publishyear, float price, int level); // Ctor
	~ActionM(); // Dtor
	ActionM(const ActionM& temp); // CCtor
	ActionM& operator=(const ActionM& temp); // operator =
	bool operator==(const ActionM& temp) const; // operator ==
	ostream& Print(ostream& os) const ; // Printing function
	friend ostream& operator<<(ostream& os, const ActionM& temp); //  Printing operator <<

private:
	int ActionLevel;
};


#endif
