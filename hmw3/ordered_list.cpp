#include <iostream>
#include <list>
#include <iterator>

using namespace std;

template <class T>
list<T> ordered_union(const list<T> & a, const list<T> & b)
{
	typename list<T>::const_iterator itr_a = a.begin();
	typename list<T>::const_iterator itr_b = b.begin();
	
	list<T> temp;
	
	while (itr_a != a.end() && itr_b != b.end()) {
		if (*itr_a < *itr_b) {
			temp.push_back(*itr_a);
			itr_a++;
		}
		else if (*itr_b < *itr_a) {
			temp.push_back(*itr_b);
			itr_b++;
		}
		else if (*itr_a == *itr_b) {
			temp.push_back(*itr_a);
			itr_a++;
			itr_b++;
		}
	}
	if (itr_a == a.end())
		while (itr_b != b.end()) {
			temp.push_back(*itr_b);
			itr_b++;
		}
		
	if (itr_b == b.end())
		while (itr_a != a.end()) {
			temp.push_back(*itr_a);
			itr_a++;
		}
	
	return temp;
}

template <class T>
list<T> ordered_intersect(const list<T> & a, const list<T> & b)
{
	typename list<T>::const_iterator itr_a = a.begin();
	typename list<T>::const_iterator itr_b = b.begin();
	
	list<T> temp;
	
	while (itr_a != a.end()) {
		if (*itr_a == *itr_b) {
			temp.push_back(*itr_a);
			cout << *itr_a << endl;
		}
		itr_a++;
		itr_b++;
	}
}

template <class T>
list<T> unordered_union(const list<T> & a, const list<T> & b)
{

}

template <class T>
list<T> unordered_intersect(const list<T> & a, const list<T> & b)
{

}

int main()
{
	list<int> l;
	list<int> l2;
	list<int> l3;
	
	l2.push_back(1);
	l2.push_back(3);

	
	l.push_back(3);
	l.push_back(5);
	
	
	l3 = ordered_intersect(l, l2);
	
	for (list<int>::iterator itr = l3.begin(); itr != l3.end(); itr++)
		cout << *itr << endl;
	
	
}
