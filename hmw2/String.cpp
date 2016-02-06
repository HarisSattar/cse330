/*
* Haris Sattar
* test.cpp
* 2/5/16
* This is the implementation of the String class
*/

#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

String::String()
{
	size = 0;
	buffer = 0;
} // String

String::String(const String & s)
{
	size = s.size;
	buffer = new char[size];
	for (int i = 0; i < size; i++)
		buffer[i] = s.buffer[i];
} // String

String::String(const char* p)
{
	size = strlen(p);
	buffer = new char[size];

	for (int i = 0; i < size; i++)
		buffer[i] = p[i];
} // String

String::~String()
{
	size = 0;
	delete[] buffer;
} // ~String

int String::length()
{
	return size;
} // length

char & String::operator[](int i)
{
	return buffer[i];
} // []

String String::operator=(const String& s)
{
	size = s.size;
	buffer = new char[size];

	for (int i = 0; i < size; i++)
		buffer[i] = s.buffer[i];

	return *this;
} // =

bool operator==(const String & left, const String & right)
{
	if (left.size != right.size)
		return false;

	for (int i = 0; i < right.size; i++)
		if (left.buffer[i] != right.buffer[i])
			return false;

	return true;
} // ==

String operator+=(String & left, const String & right)
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

ostream & operator<<(ostream & os, const String & right)
{
	for (int i = 0; i < right.size; i++)
		os << right.buffer[i];

	return os;
} // <<

bool operator<=(const String & left, const String & right)
{
	if (left == right)
		return true;

	if (left.size > right.size)
		return false;

	for (int i = 0; i < left.size; i++)
		if (left.buffer[i] > right.buffer[i])
			return false;

	return true;
} // <=

bool operator<(const String & left, const String & right)
{
	if ((left <= right) && !(left == right))
		return true;

	return false;
} // <


String operator*(const String & left, const int n)
{
	String temp;

	for (int i = 0; i < n; i++)
		temp += left;
	cout << temp.size << endl;
	return temp;
}

String operator+(const String & left, const String & right)
{
	String temp;
	int size = left.size + right.size;
	temp.size = size;

	temp.buffer = new char[size];

	int i;
	for (i = 0; i < left.size; i++)
		temp.buffer[i] = left.buffer[i];
	for (int j = 0; i < size; i++, j++)
		temp.buffer[i] = right.buffer[j];

	return temp;
}

String operator-(const String & left, const String & right)
{
	String temp = left;
	String sub = right;
	sub.buffer = new char[sub.size];
	int substart = 0, subend = 0;

	for (int start = 0; start < left.size - right.size + 1; start++) {		
		for (int i = 0; i < right.size; i++) {
			sub.buffer[i] = left.buffer[start + i];
			substart = start + i - right.size + 1;
			subend = start + i;
		}
		if (sub == right) {
			temp.size -= right.size;
			for (int j = 0; j <= temp.size; j++)
				temp[substart++] = temp[++subend];
		}			
	}
	return temp;
}
