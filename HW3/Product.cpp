#include "Product.h"

Product::~Product() // Dtor
{
	delete this->Name; // deleting the string
	this->Name = NULL;
}


Product::Product(char* name, int serial, int publishyear, float price) // Ctor
{
	int size = strlen(name); // String length
	this->Name = new char[size + 1]; // Allocating memory
	if (this->Name == NULL) // Checking if the allocation succeeded
	{
		cout << "Could not allocate memory";
		exit(1); // Exitig the program
	}
	strcpy(this->Name, name); // Copying the string 

	this->PublishingYear = publishyear;
	this->Serial = serial;
	this->Price = price;
}

Product::Product(const Product& temp) // CCtor
{
	int size = strlen(temp.Name); // String length
	this->Name = new char[size + 1]; // Allocating memory
	if (this->Name == NULL) // Checking if the allocation succeeded
	{
		cout << "Could not allocate memory";
		exit(1); // Exitig the program
	}
	strcpy(this->Name, temp.Name); // Copying the string 

	this->PublishingYear = temp.PublishingYear;
	this->Serial = temp.Serial;
	this->Price = temp.Price;
}

Product& Product::operator=(const Product& temp) // Operator =
{
	if (this != &temp) // Checking if they are the same one
	{
		int size = strlen(temp.Name); // String length
		if (this->Name != NULL)
			delete this->Name;
		this->Name = new char[size + 1]; // Allocating memory
		if (this->Name == NULL) // Checking if the allocation succeeded
		{
			cout << "Could not allocate memory";
			exit(1);  // Exitig the program
		}
		strcpy(this->Name, temp.Name); // Copying the string 

		this->PublishingYear = temp.PublishingYear;
		this->Serial = temp.Serial;
		this->Price = temp.Price;
	}

	return *this; // Returning the object 
}

bool Product::operator==(const Product& temp) const// Operator ==
{
	if (strcmp(this->Name, temp.Name) == 0) // if the names are the same
	{
		if (this->PublishingYear == temp.PublishingYear) // if the publishig year is the same
		{
				if (this->Price == temp.Price) //if the price is the same
					return true; // returning true
		}
	}
	return false; // Returning false
}

ostream& Product::Print(ostream& os) const // There is a function fo printing so there will be an option to put it as virtual
{   // Printing all the data
	os << "<" << this->Serial << "> ";
	os << "<" << this->Price << "> ";
	//os << "<" << this->Name << "> ";
	//os << "<" << this->PublishingYear << "> ";
	return os;
}

void Product::SetPrice(float price)
{
	this->Price = price; // Setting the price with the parameter
}

int Product::GetSerial() const
{
	return this->Serial;
}

char* Product::GetName() const
{
	return this->Name;
}

void  Product::SetSerial(int serial)
{
	this->Serial = serial;
}

int Product::GetPubYear() const
{
	return this->PublishingYear;
}



////////// Global functions /////////////

ostream& operator<<(ostream& os, const Product& temp) // Printing operator
{
	return temp.Print(os); // Using the print function to return os
}