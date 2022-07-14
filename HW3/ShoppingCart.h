
#include"ActionM.h"
#include"ScifiM.h"
#include"ThrillerM.h"
#include"KidsB.h"
#include"ReadingB.h"
#include"MusicAlbum.h"
#include"Shop.h"

#ifndef __SHOPPINGCART_H_
#define __SHOPPINGCART_H_

class ShoppingCart
{
public:
	ShoppingCart(); // Default Ctor
	~ShoppingCart(); // Dtor
	ShoppingCart(const ShoppingCart& temp); // CCtor
	ShoppingCart& operator=(const ShoppingCart& temp); // oprator =
	bool operator==(const ShoppingCart& temp) const; // operator ==
	ShoppingCart& operator-(const ShoppingCart& temp); // operator - Intersection of two carts
	ShoppingCart& operator+(const ShoppingCart& temp);// operator + Union of two carts
	void operator+=(Product& temp); // Adding a Product to the cart
	void operator-=(int serialTodelete); // Removing a Product from the cart
	bool ItemExists(const Product& temp) const; // Checking if an item exists if the cart
	bool ItemExists(int S) const;
	void AddExistingItem(const Product& temp, int amount); // Adding an item that already exists in the cart
	void PrintBySerial(int serial) const; // Printing a Product by its serial
	friend ostream& operator<<(ostream& os, const ShoppingCart& temp); // Printing operator <<
	void SetSerial(int s);
	void SetAmount(int amount, int serial);
	int GetCartSerial() const;
	int GetSize();
	

private:
	Product** Cart;
	int size;
	int* Quantities; // An array of int at the same size as the Cart array to save the ammouts of each Product
	int serial;
};


#endif
