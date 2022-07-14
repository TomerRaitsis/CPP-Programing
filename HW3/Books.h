

#include"Product.h"
#define MaxPrice 100
#define MinPrice 10

#ifndef __BOOKS_H_
#define __BOOKS_H_


class Books : virtual public Product
{
public:
	Books(char* name, int serial, int publishyear, float price, int numofpages); // Ctor
	virtual ~Books(); // Dtor
	Books(const Books& temp); // CCtor
	virtual Books& operator=(const Books& temp); //operator=
	virtual bool operator==(const Books& temp) const; // operator ==
	virtual ostream& Print(ostream& os) const =0; //Printing function
	friend ostream& operator<<(ostream& os, const Books& temp); // Printing operator <<
	int GetNumOfPages() const;

private:
	int NumOfPages;
};


#endif
