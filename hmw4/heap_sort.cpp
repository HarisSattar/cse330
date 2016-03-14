#include <iostream>
#include "../lab4/Vector.h"
#include "../lab9/Priority_queue.h"

using namespace std;

template <class T>
void heap_sort(T & c)
{
	Priority_queue<int> pq;
	typename T::iterator itr;
	for (itr = c.begin(); itr != c.end(); itr++)
		pq.push(*itr);
		
	for (itr = c.end(); itr != c.begin(); itr--) {
		//cout << pq.top() << endl;
		*itr = pq.top();
		cout << *itr << endl;
		pq.pop();
	}
}

int main()
{
	Vector<int> v;
	int input;
	
	while (cin >> input)
		v.push_back(input);
		
	heap_sort(v);
	
	for (Vector<int>::iterator i = v.begin(); i != v.end(); i++)
		cout << *i << " ";
	
	cout << endl;
}
