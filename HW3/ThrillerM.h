

#include"Product.h"
#define MoviePrice 20

#ifndef __THRILLER_H_
#define __THRILLER_H_


class ThrillerM : virtual public Product
{
public:
	ThrillerM(char* name, int serial, int publishyear, float price, int level); //Ctor
	~ThrillerM(); // Dtor
	ThrillerM(const ThrillerM& temp); // CCtor
	ThrillerM& operator=(const ThrillerM& temp); // operator =
	bool operator==(const ThrillerM& temp) const; // operator ==
	ostream& Print(ostream& os) const ; // Printing function
	friend ostream& operator<<(ostream& os, const ThrillerM& temp); //  Printing operator <<

private:
	int ThrilerLevel;
};


#endif
