#include "Song.h"

Song::Song() // Default Ctor
{
    this->Name = NULL;
    this->SongLength = 0;
}

Song::Song(char* name, int length) // Ctor with values
{
    int size = strlen(name);
    this->Name = new char[size + 1];
    if (this->Name == NULL)
    {
        cout << "Could not allocate memory";
        exit(1);
    }
    strcpy(this->Name, name);
    this->SongLength = length;
}

Song::~Song() // Dtor
{
    delete this->Name;
}

Song::Song(const Song& temp) // CCtor
{
    int size = strlen(temp.Name); // Size of string
    this->Name = new char[size + 1]; // Allocating memory
    if (this->Name == NULL)
    {
        cout << "Could not allocate memory";
        exit(1);
    }
    strcpy(this->Name, temp.Name); // Copying the name
    this->SongLength = temp.SongLength; // Setting the length
}

Song& Song::operator=(const Song& temp) // Operator =
{
    if (this != &temp) // Checking if they are the same
    {
        int size = strlen(temp.Name); ////// if they are not the same, copying the temp to the object
        if (this->Name != NULL)
            delete this->Name;
        this->Name = new char[size + 1];
        if (this->Name == NULL)
        {
            cout << "Could not allocate memory";
            exit(1);
        }
        strcpy(this->Name, temp.Name);
        this->SongLength = temp.SongLength;
    }
    return *this;
}

bool Song::operator==(const Song& temp) const // Checking if equal
{
    if (this->SongLength == temp.SongLength) // Checking song length
    {
        if (strcmp(this->Name, temp.Name) == 0) // Checking name
            return true;
    }
    return false;
}

void Song::SetName(char* name) // Setting name for the song
{
    int size = strlen(name); // Getting size
    this->Name = new char[size + 1]; // Allocating memory
    if (this->Name == NULL)
    {
        cout << "Could not allocate memory";
        exit(1);
    }
    strcpy(this->Name, name); // Copying name
}

void Song::SetLength(int length) // Seting length
{
    this->SongLength = length;
}

////////// Global functions /////////////

ostream& operator<<(ostream& os, const Song& temp) // Printing song
{
    os <<"<"<< "Song" << "> " << "<" << temp.Name << "> ";
    os << "<" << temp.SongLength << "> ";
    return os;
}
