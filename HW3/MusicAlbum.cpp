#include "MusicAlbum.h"


MusicAlbum::MusicAlbum(char* name, int serial, int publishyear, float price, Song* Album1, int size) : Product(name, serial, publishyear, price)
{
    float Bprice = size * 5; // The price (number of songs * 5)
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

    this->SongsNum = size; // Stting the size
    this->Album = new Song[this->SongsNum]; // Allocating memory
    if (this->Album == NULL)
    {
        cout << "Could not allocate memory" << endl;
        exit(1);
    }

    for (int i = 0; i < this->SongsNum; i++)
    {
        this->Album[i] = Album1[i]; //Copying a the songs
    }
}

MusicAlbum::~MusicAlbum()
{
    delete[] this->Album;
}

MusicAlbum::MusicAlbum(const MusicAlbum& temp) : Product(temp)
{
    this->SongsNum = temp.SongsNum; // Getting the number of songs
    this->Album = new Song[this->SongsNum]; // Allocating memory
    if (this->Album == NULL)
    {
        cout << "Could not allocate memory" << endl;
        exit(1);
    }

    for (int i = 0; i < this->SongsNum; i++)
    {
        this->Album[i] = temp.Album[i]; // Copying all the songs
    }
}

MusicAlbum& MusicAlbum::operator=(const MusicAlbum& temp) // Operator =
{
    if (this != &temp) // if they are not the same, will copy the temp to the object
    {
        this->SongsNum = temp.SongsNum;
        if (this->Album != NULL)
            delete this->Album;
        this->Album = new Song[this->SongsNum];
        if (this->Album == NULL)
        {
            cout << "Could not allocate memory" << endl;
            exit(1);
        }

        for (int i = 0; i < this->SongsNum; i++)
        {
            this->Album[i] = temp.Album[i];
        }
    }
    return *this;
}

bool MusicAlbum::operator==(const MusicAlbum& temp) const // Checkin g if are equal
{
    int count = 0;

    if (this->SongsNum != temp.SongsNum) // if same number of songs
        return false;
    for (int i = 0; i < this->SongsNum; i++)
    {
        if (this->Album[i] == temp.Album[i]) // Counting the amount of same songs
            count++;
    }

    if (count == this->SongsNum) // Checking if they all are the same
    {
        return true;
    }
    else
        return false;
}

ostream& MusicAlbum::Print(ostream& os) const // Printing the album
{
    Product::Print(os);
    os << "<" << "Music Album" << "> " ;
    os << "<" << this->GetName() << "> ";
    os << "<" << this->GetPubYear() << "> " << endl;
    for (int i = 0; i < this->SongsNum; i++)
    { 
        os << "\t";
        os << this->Album[i];
        os << endl;
    }
    return os;
}

////////// Global functions /////////////

ostream& operator<<(ostream& os, const MusicAlbum& temp)
{
    return temp.Print(os);
}