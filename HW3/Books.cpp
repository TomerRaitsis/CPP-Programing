#include"Books.h"

//Books::Books(): Product()
//{
	//this->NumOfPages = 0;
//}

Books::Books(char* name, int serial, int publishyear, float price, int numofpages): Product(name, serial, publishyear, price) // Using the Product Ctor
{
	this->NumOfPages = numofpages;
}

Books:: ~Books() // Ctor
{

}

Books::Books(const Books& temp): Product(temp) // Using the Products CCtor
{
	this->NumOfPages = temp.NumOfPages;
}

Books& Books::operator=(const Books& temp) //operator=
{
	if (this != &temp) // Checking if they are the same
	{
		Product::operator=(temp); // Using the Product operator =
		this->NumOfPages = temp.NumOfPages;
	}
	return *this; // returning the object
}

bool Books::operator==(const Books& temp) const // operator ==
{
	if (Product::operator==(temp)) // Using the Product operator ==
	{
		if (this->NumOfPages == temp.NumOfPages) //if there is  same number of pages
			return true; // returning true
	}
	return false; //returning false
}


ostream& Books::Print(ostream& os) const // Printing function
{
	// Printing the product parameters
	os << "<" << this->NumOfPages << "> ";
	return os;
}

int Books::GetNumOfPages() const
{
	return this->NumOfPages; // returning the number of pages
}
////////// Global functions /////////////

ostream& operator<<(ostream& os, const Books& temp) // Printing operator <<
{
	return temp.Print(os); //Using the Print function to return os
}