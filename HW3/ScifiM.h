

#include"Product.h"
#define MoviePrice 20

#ifndef __SCIFIM_H_
#define __SCIFIM_H_


class ScifiM : virtual public Product
{
public:
	ScifiM(char* name, int serial, int publishyear, float price, int level); //Ctor
	~ScifiM(); // Dtor
	ScifiM(const ScifiM& temp); // CCtor
	ScifiM& operator=(const ScifiM& temp); // operator =
	bool operator==(const ScifiM& temp) const; // operator ==
	ostream& Print(ostream& os) const; // Printing function
	friend ostream& operator<<(ostream& os, const ScifiM& temp); //  Printing operator <<

private:
	int ScifiLevel;
};


#endif
