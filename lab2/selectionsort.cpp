/********************************************************************************
 * Haris Sattar
 * bubblesort.cpp
 * 1/25/16
 * This program sorts an array of random integers using selection sort.
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
    
    //selection sort
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++)
            if (v[i] > v[j])
                swap(v[i], v[j]);
                
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}
