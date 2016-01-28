/********************************************************************************
 * Haris Sattar
 * bubblesort.cpp
 * 1/25/16
 * This program sorts an array of random integers using insertion sort.
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
    
	//insertion sort
    int i, j, elem;
    for (i = 1; i < n; i++) {
        for (elem = v[i], j = i-1; j >=0 && elem < v[j]; j--)
            v[j+1] = v[j];
        v[j+1] = elem;
    }
                
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}
