
// String.cpp: implementation of the String class.
//
//////////////////////////////////////////////////////////////////////

#include "String.h"
#include <string.h>
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor/default constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
String::String(const char* str/*=NULL*/)
{
	//if(str)
	//	cout<<"::converting char* to String::\n";
	//else
	//	cout<<"::default constructor::\n";
	
	if(str){
		m_iLen = strlen(str);
		m_str = new char[m_iLen + 1];
		strcpy(m_str,str);
	}
	else{
		m_str = NULL;
		m_iLen = 0;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// copy constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
String::String(const String& str)
{
	/*cout<<"::copy constructor::\n";*/
	m_iLen = str.m_iLen;
	if (str.m_str)
	{
		m_str = new char[m_iLen + 1];
		strcpy(m_str,str.m_str);
	}
	else
		m_str = NULL;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
String::~String()
{
	/*cout<<"::destructor::\n";*/
	if(m_str)
	{
		delete[] m_str;
		m_str = NULL;
	}
}

//////////////////////////////////////////////////////////////////////
// Methods (public interface)
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Insert
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void String::Insert(int index_pos,const String& str)
{
	assert((index_pos >= 0) && (index_pos <= m_iLen));
	int iNewLen = m_iLen + str.m_iLen;
	char *pStr = new char[iNewLen + 1];
	if (m_str)
		strncpy(pStr, m_str, index_pos);
	if (str.m_str)
		strcpy(pStr + index_pos, str.m_str);
	if (m_str)
	{
		strcpy(pStr + index_pos + str.m_iLen, m_str + index_pos);
		delete[] m_str;
	}
	m_str = pStr;
	m_iLen = iNewLen;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Remove
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int String::Remove(int index_pos,int length)
{
	assert((index_pos >= 0) && (index_pos <= m_iLen));
	assert(length <= m_iLen - index_pos);
	int iNewLen = m_iLen - length;
	if (iNewLen == 0)
	{
		delete[] m_str;
		m_str = NULL;
	}
	else
	{
		char *pStr = new char[iNewLen + 1];
		strncpy(pStr, m_str, index_pos);
		strcpy(pStr + index_pos, m_str + index_pos + length);
		delete[] m_str;
		m_str = pStr;
	}
	m_iLen = iNewLen;
	return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Find
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int String::Find(const String& str) const
{
	int i, j;
	if ((!m_str) || (!str.m_str))
	{
		return -1;
	}
	for (i=0; m_str[i]; ++i)
	{
		for (j=0; m_str[i+j] && str.m_str[j] && (m_str[i+j] == str.m_str[j]); ++j);
		if (!str.m_str[j])
			return i;
	}
	return -1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Substr
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
String String::Substr(int index_pos,int iCount) const
{
	assert((index_pos >= 0) && (index_pos <= m_iLen));
	String retVal;
	retVal.m_iLen = index_pos + iCount <= m_iLen ? iCount : m_iLen - index_pos;
	retVal.m_str = new char[retVal.m_iLen + 1];
	strncpy (retVal.m_str, m_str + index_pos, iCount);
	return retVal;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Replace
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int String::Replace(const String& s, const String& t)
{
	int pos = Find(s);
	if (pos == -1)
		return 0;

	int iNewLen = m_iLen - s.m_iLen + t.m_iLen;
	char *pStr = new char[iNewLen + 1];
	strncpy(pStr, m_str, pos);
	if (t.m_str)
		strcpy(pStr + pos, t.m_str);
	strcpy(pStr + pos + t.m_iLen, s.m_str);
	return 0;
}

///////////////////// operators ///////////////////// 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator =
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
String& String::operator = (const String& str)
{
	//checking self-assignments
	if(this != &str)
	{
		//check if there's memory to release
		if(m_str)
		{
			delete[] m_str;
			m_str = NULL;
		}
		//copy str to currect string
		m_iLen = str.m_iLen;
		if (str.m_str)
		{
			m_str = new char[m_iLen+1];
			strcpy(m_str , str.m_str);
		}
	}
	
	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator +=
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
String& String::operator += (const String& str)
{
	if (!str.m_str)
	{
		return *this;
	}
	//else:
	if(m_str)
	{
		int iNewLen = m_iLen + str.m_iLen;
		char* sNewStr = new char[iNewLen+1];
		strcpy(sNewStr,m_str);
		
		//concatenate the two strings
		strcat(sNewStr,str.m_str);

		delete[] m_str;
		m_str = NULL;

		//update the member attributes:
		m_str = sNewStr;
		m_iLen = iNewLen;
	}
	else //m_str is empty
	{
		m_iLen = str.m_iLen;
		m_str = new char[m_iLen+1];
		strcpy(m_str,str.m_str);
	}

	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator []
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char& String::operator [] (int iIndex) const
{
	assert(iIndex>=0 && iIndex<m_iLen);
	return m_str[iIndex];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator +
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const String String::operator + (const String& s2) const
{
	String sResult = (*this);
	sResult+=s2;
	return sResult;
}


///////////////////// logical operators ///////////////////// 

bool String::operator == (const String& s2) const
{
	if ((m_str) && (s2.m_str))
		return strcmp(m_str , s2.m_str) == 0;
	else
		return ((m_str==NULL) && (s2.m_str==NULL));
}

bool String::operator != (const String& s2) const
{
	return !((*this)==s2) ;
}

bool String::operator < (const String& s2) const
{
	if ((m_str) && (s2.m_str))
		return strcmp(m_str , s2.m_str) < 0;
	else
		return ((m_str==NULL) && (s2.m_str!=NULL));
}

bool String::operator > (const String& s2) const
{
	return (s2<(*this));
}

bool String::operator <= (const String& s2) const
{
	return (((*this)<s2) || ((*this)==s2));
}

bool String::operator >= (const String& s2) const
{
	return (s2<=(*this));
}

//////////////////////////////////////////////////////////////////////
// Friend Functions 
//////////////////////////////////////////////////////////////////////

///////////////////// I/O operators ///////////////////// 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator <<
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ostream& operator << (ostream& out, const String& str)
{
	//verify that string is not empty to avoid access violation
	if(str.m_str){
		out<<str.m_str;
	}

	return out;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator >>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
istream& operator >> (istream& in, String& str)
{
	char sBuffer[String::MAXSIZE];
	in.getline(sBuffer,String::MAXSIZE);
	str = sBuffer;
	return in;
}
