/*
* Haris Sattar
* String.h
* 2/5/16
* This is the header file for String.cpp
*/

#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String {
	int size;
	char * buffer;
public:
	String();
	String(const String &);
	String(const char *);
	~String();

	// other methods
	int length();
	char & operator[](int i);
	String operator=(const String&);

	friend bool operator==(const String &, const String &);
	friend String operator+=(String &, const String &);
	friend ostream & operator<<(ostream &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator<(const String &, const String &);
}; // String

#endif
