/*
 * Haris Sattar
 * test.cpp
 * 2/5/16
 * this tests < and <= for String class
 */
 
#include <iostream>
#include "String.h"

using namespace std;

main()
{
	String s1("bbbbbbb"), s2("abe");

	if ( not (s1 == s2) )
		if (s1 <= s2)
			cout << s1 << " <= " << s2 << endl;
		else
			cout << s1 << " > " << s2 << endl;
	else
		cout << "equal: " << s1 << " " << s2;
} // main