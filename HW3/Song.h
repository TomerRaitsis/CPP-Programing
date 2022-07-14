

#ifndef __SONG_H_
#define __SONG_H_

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class Song
{
public:
	Song(); // Default Ctor
	Song(char* name, int lengh); // Ctor
	virtual~Song(); // Dtor
	Song(const Song& temp); // CCtor
	Song& operator=(const Song& temp); // Operator =
	bool operator==(const Song& temp) const; // Operator ==
	friend ostream& operator<<(ostream& os, const Song& temp);
	void SetName(char* name);
	void SetLength(int length);

private:
	char* Name;
	int SongLength;
};


#endif
