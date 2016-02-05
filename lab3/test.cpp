#include <iostream>
#include "String.h"
#include <string>

using namespace std;

main()
{
	String s1("abcd"), s2("abe");
	
	string s3 = "abcd", s4 = "abe";

	if (s3 <= s4)
	  	cout << s3 << " <= " << s4 << endl;
	else
		 cout << s3 << " > " << s4 << endl;

	if ( not (s1 == s2) )
		if (s1 <= s2)
			cout << s1 << " <= " << s2 << endl;
		else
			cout << s1 << " > " << s2 << endl;
	else
		cout << "equal: " << s1 << " " << s2;
}
