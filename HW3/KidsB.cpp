#include "KidsB.h"

KidsB::KidsB(char* name, int serial, int publishyear, float price, int numofpages, int minage): Product(name, serial, publishyear, price), Books(name, serial, publishyear, price, numofpages)  //Using the Books and Product Ctor
{
    this->MinAge = minage;
    float Bprice  = this->GetNumOfPages() / 2; // The price (number of pages / 2)
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



KidsB::~KidsB() // Dtor
{

}


KidsB::KidsB(const KidsB& temp): Product(temp),Books(temp) // Using Product and Books CCtor
{
    this->MinAge = temp.MinAge;
}


KidsB& KidsB::operator=(const KidsB& temp) // Operator =
{
    if (this != &temp) // Checking if they are the same
    {
        Books::operator=(temp); // Using the biiks operator =
        this->MinAge = temp.MinAge;
    }
    return *this; // Rturning the object
}

bool KidsB::operator==(const KidsB& temp) const // Operator ==
{
    if (Books::operator==(temp)) // Using the Books operator ==
    {
        if (this->MinAge == temp.MinAge) // If the minimum age is the same
            return true; // Returning true
    }
    return false; // returning false
   
}

ostream& KidsB::Print(ostream& os) const
{
    Product::Print(os);
    os << "<" << "Children Book" << "> ";
    os << "<" << this->GetName() << "> " ;
    os << "<" << this->GetPubYear() << "> " ;
    Books::Print(os); // Using the Books function to print the Books parameters
    os << "<" << this->MinAge << "> "<< endl;
    return os;
}


////////// Global functions /////////////

ostream& operator<<(ostream& os, const KidsB& temp)
{
   return temp.Print(os); // Using the print functioin to return the os
}
