#include "ActionM.h"

ActionM::ActionM(char* name, int serial, int publishyear, float price, int level): Product(name, serial, publishyear, price) // Using the Product Ctor
{
    this->ActionLevel = level;
    this->SetPrice(MoviePrice);
}

ActionM::~ActionM() // Dtor
{

}

ActionM::ActionM(const ActionM& temp): Product(temp) // Using the Product CCtor
{
    this->ActionLevel = temp.ActionLevel;
}

ActionM& ActionM::operator=(const ActionM& temp)
{
    if (this != &temp)
    {
        Product::operator=(temp);  // Using the product operator =
        this->ActionLevel = temp.ActionLevel;
    }
    return *this; // returning the object
}

bool ActionM::operator==(const ActionM& temp) const
{
    if (Product::operator==(temp)) // Using the Product operator ==
    {
        if (this->ActionLevel == temp.ActionLevel) // Checking the Thriler level
            return true; // returning true
    }
    return false;  // returning false
}

ostream& ActionM::Print(ostream& os) const
{
    Product::Print(os); // Using the Product print function
    os << "<" << "Action Movie" << "> ";
    os << "<" << this->GetName() << "> " ;
    os << "<" << this->GetPubYear() << "> " ;
    os << "<" << this->ActionLevel << "> " << endl;
    return os;
}

////////// Global functions /////////////

ostream& operator<<(ostream& os, const ActionM& temp)
{
    return temp.Print(os); // Using the print function to retrun the os
}
