#include "ScifiM.h"

ScifiM::ScifiM(char* name, int serial, int publishyear, float price, int level): Product(name, serial, publishyear, price) // Ctor
{
    this->ScifiLevel = level;
    this->SetPrice(MoviePrice);
}

ScifiM::~ScifiM() // Dtor
{

}

ScifiM::ScifiM(const ScifiM& temp): Product(temp) // CCtor
{
    this->ScifiLevel = temp.ScifiLevel;
}

ScifiM& ScifiM::operator=(const ScifiM& temp) // Operator =
{
    if (this != &temp)
    {
        Product::operator=(temp);
        this->ScifiLevel = temp.ScifiLevel;
    }
    return *this;
}

bool ScifiM::operator==(const ScifiM& temp) const // Operator ==
{
    if (this->operator==(temp))
    {
        if (this->ScifiLevel == temp.ScifiLevel)
            return true;
    }
    return false;
}

ostream& ScifiM::Print(ostream& os) const // Function for printing
{
    Product::Print(os);
    os << "<" << "Sci-fi Movie" << "> ";
    os << "<" << this->GetName() << "> " ;
    os << "<" << this->GetPubYear() << "> " ;
    os << "<" << this->ScifiLevel << "> " << endl ;
    return os;
}


////////// Global functions /////////////

ostream& operator<<(ostream& os, const ScifiM& temp) // Printing operator
{
    return temp.Print(os);
}
