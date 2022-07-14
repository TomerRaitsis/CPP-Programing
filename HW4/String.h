
#define _CRT_SECURE_NO_WARNINGS
// String.h: interface for the String class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

class String  
{
	enum{MAXSIZE=1024};
public:
	//-- constructors/destructor --//
	String(const char* str=NULL);
	String(const String&);
	~String();

	//-- operators --//
	String& operator=(const String&);
	String& operator+=(const String&);

	const String operator+(const String&) const;

	//logical operators
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator<(const String&) const;
	bool operator>(const String&) const;
	bool operator<=(const String&) const;
	bool operator>=(const String&) const;

	//I/O operator
	friend ostream& operator<<(ostream& , const String&);
	friend istream& operator>>(istream& , String&);

	//indexing operator
	char& operator[](int) const;

	//casting operator
	operator char*() const;

	//-- methods --//
	int  Length() const;
	void Insert(int index_pos,const String&);
	int  Remove(int index_pos,int length);
	//finds a substring in the current string.
	int  Find(const String&) const;
	//returns count characters String starting at index_pos.
	String Substr(int index_pos,int iCount) const;
	//replaces substring s with substring t.
	int  Replace(const String& s, const String& t);

private:
	//-- data members --//
	char*	m_str;	//pointer to dynamically allocated data.
	int		m_iLen;	//current length of the string.
};

///////////////////// inline functions /////////////////////

inline int String::Length() const
{
	return m_iLen;
}

inline String::operator char*() const
{
	return m_str;//what is the logical problem here?
}

#endif //__STRING_H__
