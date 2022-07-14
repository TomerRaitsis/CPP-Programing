#include "Shop.h"

Shop::Shop() // Default Ctor
{
    this->Products = NULL; // Setting to NULL
    this->size = 0; // Setting to 0
}

Shop::~Shop() // Dtor
{
    for (int i = 0; i < this->size; i++) // Deleting the dynamicaly allocated Products
    {
        delete this->Products[i];
    }
    delete this->Products;
}

void Shop::operator+=(Product& temp) // Adding a Product
{
    Product** T = NULL;
    T = new Product * [this->size + 1]; // Allocating a bigger array by 1 spot
    if (T == NULL)
    {
        cout << "Could not allocate memory" << endl; // Checking if allocation worked
        exit(1); // Exiting if it didn't work
    }

    for (int i = 0; i < this->size; i++) // Copying the existing array
    {
        T[i] = this->Products[i];
    }

    T[this->size] = &temp; // adding the new Product

    delete this->Products; // deleting the ** array
    this->Products = T;
    this->size++;
}

int Shop::operator-=(int serialTodelete) // Removing a Product
{
    Product** T = NULL;
    int index = -1;
    for (int i = 0; i < this->size; i++)
    {
        if (serialTodelete == this->Products[i][0].GetSerial()) // Incase the serial number ( Product ) exists getting it's index
            index = i;
    }

    if (index != -1) // If the Product is in the shop
    {
        T = new Product * [this->size - 1]; // Allocating a smaller array by 1
        if (T == NULL)
        {
            cout << "Could not allocate memory" << endl; // Checking allocation
            exit(1); // Exiting if it didn't work
        }

        for (int i = 0; i < index; i++) // Copying the existing array untill the index
        {
            T[i] = this->Products[i];
        }
        int j = index + 1; // Skipping the Product we need to remove
        for (int i = index; i < this->size - 1; i++) // Copying the rest of the array
        {
            T[i] = this->Products[j];
            j++;
        }
        delete this->Products; // deleting the Previuos array
        this->Products = T;
        this->size--; // size - 1
    }
    return index;
}

int Shop::PrintByIndex(int serial) const // Printing a Product from the shop by it's index
{
    int CheckforPrint = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (serial == this->Products[i][0].GetSerial())// looking for a Product with th given serial
        {
            cout << this->Products[i][0];
            CheckforPrint++;
        }    
    }
    return CheckforPrint;
}

bool Shop::ItemExists(Product& temp) const
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->Products[i][0] == temp) // Checking if the item exists
            return true;
    }
    return false;
}

void Shop::PrintShopMneu() const // Printing the Shop menu
{
    cout << "-------------------------------------" << endl;
    cout << "1.Add new item" << endl;
    cout << "2.Delete item" << endl;
    cout << "3.Print item" << endl;
    cout << "4.Print all items" << endl;
    cout << "5.Return" << endl;
    cout << "-------------------------------------" << endl;
}


Product* Shop::GetProduct(int serial) const // Getting a Product By its serial
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->Products[i][0].GetSerial() == serial)
            return &this->Products[i][0];
    }
    return NULL;
}

int Shop::GetSize() const // Getting the size of the shop( amount of products )
{
    return this->size;
}

char* Shop::getstring() const // A function that gets a full sentence from the user
{
    char buff = ' ';
    char Word[MaxDigits] = "\0";
    char Sentence[MaxDigits] = "\0";

    while (buff == ' ')
    {
        cin >> Word;
        strcat(Sentence, Word);
        buff = getchar();
        if(buff == ' ') // Checking if there is a space between the words
            strcat(Sentence, " ");
    }

    return Sentence;
}

char* Shop::GetWord(char* string, int* index) const // Getting a word from the sentence, Between "<   >"
{
    int j = 0;
    char* word = new char[50];
    while (string[*index] != '>') // While it is not the end of the < >
    {
        if (string[*index] != '<') // if it is not < 
        {
            if (string[*(index)-1] != '>' && string[*(index)+1] != '<') // If it is not a space between two >  <
            {
                char c = string[*index];
                strcpy(&word[j], &c); // Copyig the current character
                j++;
            }
        }
        *index = *index + 1; // Index ++
    }
    word[j] = '\0'; // End of the Word
    *index = *index + 1; //Index++
    return word;
}

////////// Global functions /////////////

ostream& operator<<(ostream& os, const Shop& temp) // Printing the shop
{
    for (int i = 0; i < temp.size; i++) // Printing all the shop
    {
        os << temp.Products[i][0];
    }
    os << endl;
    return os;
}

