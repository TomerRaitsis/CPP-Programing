#include "ReadingB.h"

ReadingB::ReadingB(char* name, int serial, int publishyear, float price, int numofpages, char* genre):Product(name, serial, publishyear, price),Books(name, serial, publishyear, price, numofpages) // Using Product and Books Ctor
{
    int size = strlen(genre);
    this->Genre = new char[size + 1]; // Allocating memory
    if (this->Genre == NULL) // Checking allocation
    {
        cout << "Could not allocate memory";
        exit(1); // Exiting the program if the allocation failed
    }
    strcpy(this->Genre, genre); // Copying the genre to it's place in the object
    float Bprice = this->GetNumOfPages() * 2; // The price (number of pages / 2)
    if (Bprice >= MinPrice || Bprice <= MaxPrice)
    {
        this->SetPrice(Bprice); // If the price is in range
    }
    else if (Bprice < MinPrice)
    {
        this->SetPrice(MinPrice); // If the price is too low
    }
    else
        this->SetPrice(MaxPrice); // If the price is too high
}

ReadingB::~ReadingB()
{
    delete this->Genre; // deleleting the string
}

ReadingB::ReadingB(const ReadingB& temp):Product(temp),Books(temp) // Using the Product and Books CCtor
{
    int size = strlen(temp.Genre);
    this->Genre = new char[size + 1]; // Allocating memory
    if (this->Genre == NULL) // Checking allocation
    {
        cout << "Could not allocate memory";
        exit(1); // Exiting the program if the allocation failed
    }
    strcpy(this->Genre, temp.Genre); // Copying the genre to it's place in the object
}

ReadingB& ReadingB::operator=(const ReadingB& temp) // Operator =
{
    if (this != &temp) // Checking if the objects are not the same 
    {
        Books::operator=(temp); // Using the Books operator =
        int size = strlen(temp.Genre);
        this->Genre = new char[size + 1]; // Allocating memory
        if (this->Genre == NULL) // Checking allocation
        {
            cout << "Could not allocate memory";
            exit(1); // Exiting the program if the allocation failed
        }
        strcpy(this->Genre, temp.Genre); // Copying the genre to it's place in the object
    }
    return *this; // Returning the object 
}

bool ReadingB::operator==(const ReadingB& temp) const // Operator ==
{
    if (Books::operator==(temp)) // Using Books Operator ==
    {
        if (strcmp(this->Genre, temp.Genre) == 0) // Checking if the genre is the same
            return true; // Returning true
    }
    return false; // Returning false
}

ostream& ReadingB::Print(ostream& os) const
{
    Product::Print(os);
    os << "<" << "Reading Book" << "> ";
    os << "<" << this->GetName() << "> " ;
    os << "<" << this->GetPubYear() << "> " ;
    Books::Print(os); //Using the Books Print function
    os << "<" << this->Genre << "> " << endl;
    return os;
}


////////// Global functions /////////////

ostream& operator<<(ostream& os, const ReadingB& temp)
{
    return temp.Print(os); // Using to print function to return the os
}
