/********************************************************************************
 * Haris Sattar
 * bubblesort.cpp
 * 1/25/16
 * This program sorts an array of random integers using bubble sort.
 ********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

	srand(time(NULL));
	    
    for (int i = 0; i < n-1; i++) {
        v[i] = rand() % 1000000;
    }
    
    //bubble sort
    int i, j;
    for (i = n-1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
                swap(v[j], v[j+1]);
                
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}
