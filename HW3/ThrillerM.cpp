#include "ThrillerM.h"

ThrillerM::ThrillerM(char* name, int serial, int publishyear, float price, int level): Product(name, serial, publishyear, price) // Using the Product Ctor
{
    this->ThrilerLevel = level;
    this->SetPrice(MoviePrice); // Setting the price
}

ThrillerM::~ThrillerM() // Dtor
{

}

ThrillerM::ThrillerM(const ThrillerM& temp): Product(temp) // Using the Product CCtor
{
    this->ThrilerLevel = temp.ThrilerLevel;
}

ThrillerM& ThrillerM::operator=(const ThrillerM& temp)
{
    if (this != &temp)
    {
        Product::operator=(temp); // Using the product operator =
        this->ThrilerLevel = temp.ThrilerLevel;
    }
    return *this; // returning the object
}

bool ThrillerM::operator==(const ThrillerM& temp) const
{
    if (Product::operator==(temp)) // Using the Product operator ==
    {
        if (this->ThrilerLevel == temp.ThrilerLevel) // Checking the Thriler level
            return true; // returning true
    }
    return false; // returning false
}

ostream& ThrillerM::Print(ostream& os) const
{
    Product::Print(os); // Using the Product print function
    os << "<" << "Thriller Movie" << "> ";
    os << "<" << this->GetName() << "> " ;
    os << "<" << this->GetPubYear() << "> " ;
    os << "<" << this->ThrilerLevel << "> " << endl;
    return os;
}


////////// Global functions /////////////

ostream& operator<<(ostream& os, const ThrillerM& temp)
{
    return temp.Print(os); // Using the print function to retrun the os
}
