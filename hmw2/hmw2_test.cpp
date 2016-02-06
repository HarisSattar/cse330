#include <cassert>
#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String s1("firetruckfiretruck");
	String s2("truck");

	String s3 = s1 - s2;

	cout << s3 << endl;

	//assert(s3 == "wf");

	cout << "SUCCESS" << endl;

} // main
