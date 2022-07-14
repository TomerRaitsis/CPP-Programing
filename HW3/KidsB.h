

#include"Books.h"

#ifndef __KIDSB_H_
#define __KIDSB_H_


class KidsB :  public Books
{
public:
	KidsB(char* name, int serial, int publishyear, float price, int numofpages, int minage); // Ctor
	~KidsB(); // Dtor
	KidsB(const KidsB& temp); // CCtor
	KidsB& operator=(const KidsB& temp); // Operator =
	virtual bool operator==(const KidsB& temp) const; // Operator ==
	ostream& Print(ostream& os) const; // Print function
	friend ostream& operator<<(ostream& os, const KidsB& temp); // Print operator <<

private:
	int MinAge;
};


#endif
