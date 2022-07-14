

#ifndef __PRODUCT_H_
#define __PRODUCT_H_

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class Product // Abstract class
{
public:
	Product(char* name, int serial, int publishyear, float price); // Ctor
	Product(const Product& temp); // CCtor
	virtual ~Product(); // Dtor
	virtual Product& operator=(const Product& temp) ; // operator = 
	virtual bool operator==(const Product& temp) const; // operator ==
	virtual ostream& Print(ostream& os) const =0; // Printing function
	friend ostream& operator<<(ostream& os, const Product& temp); //  Printing operator <<
	void SetPrice(float price);
	int GetSerial() const ;
	char* GetName() const;
	void SetSerial(int serial);
	int GetPubYear() const;

private:
	char* Name;
	int PublishingYear;
	int Serial;
	float Price;
};


#endif
