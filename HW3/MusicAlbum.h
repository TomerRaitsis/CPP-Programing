

#include"Product.h"
#include"Song.h"
#define MaxPrice 100
#define MinPrice 10

#ifndef __MUSICALBUM_H_
#define __MUSICALBUM_H_


class MusicAlbum : virtual public Product
{
public:
	MusicAlbum(char* name, int serial, int publishyear, float price, Song* Album, int size);
	~MusicAlbum();
	MusicAlbum(const MusicAlbum& temp);
	MusicAlbum& operator=(const MusicAlbum& temp);
	bool operator==(const MusicAlbum& temp) const;
	 ostream& Print(ostream& os) const ; //Printing function
	friend ostream& operator<<(ostream& os, const MusicAlbum& temp);


private:
	Song* Album;
	int SongsNum;
};


#endif
