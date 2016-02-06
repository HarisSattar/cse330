#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

String::String()
{
	size = 0;
	buffer = 0;
}

String::String(const String & s)
{
	size = s.size;
	buffer = new char[size];
	for (int i = 0; i < size; i++)
		buffer[i] = s.buffer[i];
}

String::String(const char* p)
{
	size = strlen(p);
	buffer = new char[size];
	
	for (int i = 0; i < size; i++)
		buffer[i] = p[i];
}

String::~String()
{
	size = 0;
	delete buffer;
}

int String::length()
{
	return size;
}

char & String::operator[](int i)
{
	return buffer[i];
}

String String::operator=(const String& s)
{
	size = s.size;
	buffer = new char[size];
	
	for (int i = 0; i < size; i++)
		buffer[i] = s.buffer[i];
		
	return *this;
}

bool operator==(const String & left, const String & right)
{
	if (left.size != right.size)
		return false;
	
	for (int i = 0; i < right.size; i++)
		if (left.buffer[i] != right.buffer[i])
			return false;
	
	return true;
}

String& operator+=(String & left, const String & right)
{
	String temp = left;
	int size = left.size + right.size;
	left.buffer = new char[size];
	
	int i;
	for (i = 0; i < left.size; i++)
		left.buffer[i] = temp.buffer[i];
		
	left.size = left.size + right.size;
	
	for (int j = 0; i < size; i++, j++)
		left.buffer[i] = right.buffer[j];
		
	return left;
}

ostream & operator<<(ostream & os, const String & right)
{
	for (int i = 0; i < right.size; i++)
		os << right.buffer[i];
	
	return os;
}

bool operator<=(const String & left, const String & right)
{
	if (left == right)
		return true;

	if (left.size > right.size)
		return false;

	for(int i = 0; i < left.size; i++)
		if (left.buffer[i] > right.buffer[i])
			return false;

	return true;
}

bool operator<(const String & left, const String & right)
{
	if ((left <= right) && !(left == right))
		return true;

	return false;
}