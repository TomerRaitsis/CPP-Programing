

#include"Product.h"
#include"ActionM.h"
#include"ScifiM.h"
#include"ThrillerM.h"
#include"KidsB.h"
#include"ReadingB.h"
#include"MusicAlbum.h"
#define MovieMinLVL 1
#define ActionMAXlvl 5
#define ScifiMAXlvl 9
#define ThrillerMAXlvl 6
#define CurrentYear 2021
#define MaxDigits 250

#ifndef __SHOP_H_
#define __SHOP_H_

class Shop
{
public:
	Shop(); // Default Ctor
	~Shop(); // Dtor
	void operator+=(Product& temp); // operator += for adding a Product
	int operator-=( int serialTodelete); // operator -= for removing a Product
	int PrintByIndex(int serial) const; // Printinf a Product by a given index
	friend ostream& operator<<(ostream& os, const Shop& temp); // Printing operator <<
	bool ItemExists(Product& temp) const; // Checking if an item exists if the cart
	void PrintShopMneu() const;
	Product* GetProduct(int serial) const;
	int GetSize() const;
	char* getstring() const;
	char* GetWord(char* string, int* i) const;

private:
	Product** Products;
	int size;
};


#endif
