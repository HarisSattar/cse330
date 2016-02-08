/*
* Haris Sattar
* String.cpp
* 2/5/16
* This is the implementation of the String class.
* This is a String class it has overloaded opertaor methods to make it more like
* the standard string class.
*/


#include "String.h"

using namespace std;

// defualt constructor for String
String::String()
{
	size = 0;
	buffer = 0;
} // String

// copy constructor for String
String::String(const String& s)
{
	size = s.size;
	buffer = new char[size];
	for (int i = 0; i < size; i++)
		buffer[i] = s.buffer[i];
} // String

// converts char string array to a String
String::String(const char* p)
{
	size = strlen(p);
	buffer = new char[size];

	for (int i = 0; i < size; i++)
		buffer[i] = p[i];
} // String

// destructor for String
String::~String()
{
	size = 0;
	delete[] buffer;
} // ~String

int String::length()
{
	return size;
} // length

//indexing operator for String
char & String::operator[](int i)
{
	return buffer[i];
} // []

// assignment operator for String
String String::operator=(const String& s)
{
	size = s.size;
	buffer = new char[size];

	for (int i = 0; i < size; i++)
		buffer[i] = s.buffer[i];

	return *this;
} // =

// function returns true if left and right strings are equal
bool operator==(const String& left, const String& right)
{
	if (left.size != right.size)
		return false;

	for (int i = 0; i < right.size; i++)
		if (left.buffer[i] != right.buffer[i])
			return false;

	return true;
} // ==

// function appends right side string to the left side string
String operator+=(String& left, const String& right)
{
	String temp = left;
	int size = left.size + right.size;
	left.buffer = new char[size];

	int i;
	for (i = 0; i < left.size; i++)
		left.buffer[i] = temp.buffer[i];

	left.size = size;

	for (int j = 0; i < size; i++, j++)
		left.buffer[i] = right.buffer[j];

	return left;
} // +=

// function that handles the output << operator
ostream & operator<<(ostream& os, const String& right)
{
	for (int i = 0; i < right.size; i++)
		os << right.buffer[i];

	return os;
} // <<

// function that tells if the left string is less than or equalt to the right
bool operator<=(const String& left, const String& right)
{
	if (left == right)
	   return true;

	if (left.size > right.size)
		for (int i = 0; i < right.size; i++)
			if (left.buffer[i] > right.buffer[i])
				return false;

	if (left.size < right.size)
		for (int i = 0; i < left.size; i++)
			if (left.buffer[i] > right.buffer[i])
				return false;

	return true;
} // <=

// same as <= operator but returns true only if it is less than
bool operator<(const String& left, const String& right)
{
	if ((left <= right) && !(left == right))
		return true;

	return false;
} // <