#include <iostream>
#include <string>
#include "../lab4/Vector.h"
#include "../lab9/Priority_queue.h"

using namespace std;



template <class Iterator>
void make_heap(Iterator start, Iterator stop)
{
	unsigned int heapSize = stop - start;
	for (int i = (heapSize / 2) - 1; i >=0; i--)
		adjust_heap(start, heapSize, i);
}

template <class Iterator>
void sort_heap(Iterator start, Iterator stop)
{
	unsigned int lastPosition = stop - start - 1;
	while (lastPosition > 0) {
		swap(start[0], start[lastPosition]);
		adjust_heap(start, lastPosition, 0);
		lastPosition--;
	}
}

template <class Iterator>
void heap_sort(Iterator start, Iterator stop)
{
	make_heap(start, stop);
	sort_heap(start, stop);
}


int main()
{
	Vector<int> v;
	int input1;
	
	while (cin >> input1)
		v.push_back(input1);
		
	heap_sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	
	cout << endl;
}
