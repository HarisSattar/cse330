#ifndef STRING_H
#define STRING_H

// String.h

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
	friend String& operator+=(String &, const String &);
	friend ostream & operator<<(ostream &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator<(const String &, const String &);
};

#endif
