#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() // Default Ctor
{
    this->Cart = NULL; // Setting to NULL
    this->size = 0; // Setting to 0
    this->Quantities = NULL; // Seting to NULL
    this->serial = 0;
}

ShoppingCart::~ShoppingCart() // Dtor
{
    delete this->Quantities; // Deleting the Quantities array
    for (int i = 0; i < this->size; i++) // Deleting the Cart array
    {
        if(this->Cart[i][0].GetSerial() > 0)
            delete this->Cart[i];
    }
    delete this->Cart; 
}

ShoppingCart::ShoppingCart(const ShoppingCart& temp) // CCtor
{
    this->serial = temp.serial;
    this->size - temp.size;
    this->Quantities = new int[temp.size];
    this->Cart = new Product*[this->size]; // Allocating an array with the same size
    if (this->Cart == NULL) // Checking allocation
    {
        cout << "Could not allocate memory" << endl;
        exit(1); // Exiting if it failed
    }
    for (int i = 0; i < this->size; i++) // Copying the arrays
    {
        this->Cart[i] = temp.Cart[i];
        this->Quantities[i] = temp.Quantities[i];
    }
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& temp) // Operator =
{
    if (this != &temp) // Checking if the object are not the same
    {
        this->serial = temp.serial;
        this->size = temp.size;
        this->Quantities = new int[temp.size];
        this->Cart = new Product * [this->size]; // Allocating an array with the same size
        if (this->Cart == NULL) // Checking allocation
        {
            cout << "Could not allocate memory" << endl;
            exit(1); // Exiting if it failed
        }
        for (int i = 0; i < this->size; i++) // Copying the arrays
        {
            this->Cart[i] = temp.Cart[i];
            this->Quantities[i] = temp.Quantities[i];
        }
    }
    return *this; // Returning the object
}

bool ShoppingCart::operator==(const ShoppingCart& temp)  const// operator ==
{
    int count = 0;
    if (this->serial == temp.serial)
    {
        if (this->size == temp.size) // Checking the amount of products
        {
            for (int i = 0; i < this->size; i++)
            {
                if (this->Cart[i][0] == temp.Cart[i][0]) // Checking if the product and thier Quantities are the same
                {
                    if (this->Quantities == temp.Quantities)
                        count++; // Adding 1 to count if they are all the same
                }
            }
        }
        if (count == this->size) // If all of the Products are the same
        {
            return true; // returning true
        }
        else
            return false; // returning false
    }
}

ShoppingCart& ShoppingCart::operator-(const ShoppingCart& temp) // operator -
{
    ShoppingCart* T = new ShoppingCart;
        //int* NewQ = NULL;
        int count = 0;
        for (int i = 0; i < this->size; i++)  // Looking fo the common Products
        {
            for (int j = 0; j < temp.size; j++)
            {
                if (this->Cart[i][0] == temp.Cart[j][0])
                    count++;
            }
        }
        int k = 0;
        T[0].Cart = new Product * [count]; // Allocating the array
        T[0].Quantities = new int[count]; // Allocating the array of the quantities
        if (T[0].Cart == NULL || T[0].Quantities == NULL)
        {
            cout << "Could not allocate memory" << endl;
            exit(1); // Exiting if allocation failed
        }
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < temp.size; j++)
            {
                if (this->Cart[i][0] == temp.Cart[j][0]) // Settig an array of the common Products
                {
                    T[0].Cart[k] = this->Cart[i];
                   
    
                    if (this->Quantities[i] >= temp.Quantities[i]) // Looking for the smaller amount
                    {
                        T[0].Quantities[i] = temp.Quantities[i];
                    }
                    else
                    {
                        T[0].Quantities[k] = this->Quantities[i];
                        
                    }
                    k++;
                }
            }
        }
        T[0].size = count;
    
    return *T; // returning the object

}

ShoppingCart& ShoppingCart::operator+(const ShoppingCart& temp) // Operator +
{
    ShoppingCart* T = new ShoppingCart;
        //int* NewQ = NULL;
        int CountForSame = 0;
        int Count = 0;

        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < temp.size; j++)
            {
                if (this->Cart[i][0] == temp.Cart[j][0]) //Counting the common Products
                {
                    CountForSame++;
                }
            }
        }

        T[0].Cart = new Product * [this->size + temp.size - CountForSame]; // Setting the array
        T[0].Quantities = new int[this->size + temp.size - CountForSame];  // Setting the array
        if (T[0].Cart == NULL || T[0].Quantities == NULL)
        {
            cout << "Could not allocate memory" << endl;
            exit(1); // Exiting if allocationg falied
        }
        for (int i = 0; i < this->size; i++) // Copying the local object array
        {
            T[0].Cart[i] = this->Cart[i];
            T[0].Quantities[i] = this->Quantities[i];
        }
        int j = this->size;
        for (int i = 0; i < temp.size; i++)
        {
            if (this->ItemExists(temp.Cart[i][0])) // Checking if the object is already exists
            {
                for (int f = 0; f < this->size; f++)
                {
                    if (this->Cart[f][0] == temp.Cart[i][0])
                    {
                        if (this->Quantities[f] < temp.Quantities[i]) // Teking the bigger amount
                            T[0].Quantities[f] = temp.Quantities[i];
                    }
                }
            }
            else // If it did not exist adding it to the array
            {
                T[0].Cart[j] = temp.Cart[i];
                T[0].Quantities[j] = temp.Quantities[i]; // updating it's amount
                j++;
            }
        }
        T[0].size = this->size + temp.size - CountForSame;

    return *T; // Returning the object

}

void ShoppingCart::operator+=(Product& temp) // Addong an item
{
    int* NewQ = new int [this->size + 1]; // Setting the array to bigger by 1
    Product** T = new Product * [this->size + 1]; // Setting the array to bigger by 1
    if (T == NULL)
    {
        cout << "Could not allocate memory" << endl;
        exit(1); // Exiting if allocation failed
    }

    for (int i = 0; i < this->size; i++) // Copying the existing array
    {
            T[i] = this->Cart[i];
            NewQ[i] = this->Quantities[i];
    }
    T[this->size] = &temp; // The new Product
    NewQ[this->size] = 1; // The Quantitie of the new Product

    delete this->Cart; // Deleting the array
    delete this->Quantities;  // Deleting the array
    this->Cart = T;
    this->Quantities = NewQ;
    this->size++;
}

void ShoppingCart::operator-=(int serialTodelete) // Removing an item
{
    Product** T = NULL;
    int* NewQ = NULL;
    int index = -1;
    for (int i = 0; i < this->size; i++)
    {
        if (serialTodelete == this->Cart[i][0].GetSerial()) // Checking if the item exists
            index = i;
    }

    if (index != -1) // If the needed item exists
    {
        T = new Product * [this->size - 1]; // Allocating the array
        NewQ = new int[this->size - 1]; // Allocating the array
        if (T == NULL)
        {
            cout << "Could not allocate memory" << endl;
            exit(1); // Exiting if allocationg failed
        }

        for (int i = 0; i < index; i++) //Copying the array untill the index
        {
            T[i] = this->Cart[i];
            NewQ[i] = this->Quantities[i];
        }
        int j = index + 1;
        for (int i = index; i < this->size - 1; i++) //Copying the rest of the array
        {
            T[i] = this->Cart[j];
            NewQ[i] = this->Quantities[i];
            j++;
        }
        delete this->Cart; // Deleting the array
        delete this->Quantities; // Deleting the array
        if (this->size == 1)
        {
            this->Cart = NULL;
            this->Quantities = NULL;
        }
        else
        {
            this->Cart = T;
            this->Quantities = NewQ;
        }
        this->size--;
    }
}

void ShoppingCart::PrintBySerial(int serial) const
{
    for (int i = 0; i < this->size; i++)
    {
        if (serial == this->Cart[i][0].GetSerial()) // Looking for the Product with this serial
            cout << this->Cart[i][0];
    }
}

bool ShoppingCart::ItemExists(const Product& temp) const
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->Cart[i][0] == temp) // Checking if the item exists
            return true;
    }
    return false;
}
 
bool ShoppingCart::ItemExists(int S) const
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->Cart[i][0].GetSerial() == S) // Checking if the serial exists
            return true;
    }
    return false;
}

void ShoppingCart::AddExistingItem(const Product& temp , int amount) // 
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->Cart[i][0] == temp) // Adding the amount to the Products quantity
            this->Quantities[i]+= amount;
    }
}

void ShoppingCart::SetSerial(int s) // Returns the serial
{
    this->serial = s;
}

void ShoppingCart::SetAmount(int amount, int serial) // Setting the amount of a specific Product
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->Cart[i][0].GetSerial() - 1 == serial)
            this->Quantities[i] = amount;
    }
}
 
int ShoppingCart::GetCartSerial() const // Returning the serial
{
    return this->serial;
}

int ShoppingCart::GetSize()
{
    return this->size;
}

////////// Global functions /////////////

ostream& operator<<(ostream& os, const ShoppingCart& temp)
{
    os << "Cart " << temp.serial << ":" << endl;
        for (int i = 0; i < temp.size; i++) // Printing the whole cart
        {
            os << temp.Cart[i][0];
            os << "<Amount> " << "<" << temp.Quantities[i] << ">" << endl;
        }
    return os;
}

