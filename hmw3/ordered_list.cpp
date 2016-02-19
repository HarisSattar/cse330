#include <iostream>
#include <list>
#include <iterator>

using namespace std;

template <class T>
void selection_sort(list<T> & l)
{
	typename list<T>::iterator i;
	typename list<T>::iterator stop_i = --(l.end());
	typename list<T>::iterator stop_j = l.end();

	for (i = l.begin(); i != stop_i; i++)
		for (typename list<T>::iterator j = i; j != stop_j; ++j)
			if (*i > *j)
				swap(*i, *j);
}

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
	list<T> temp;

	for (typename list<T>::const_iterator itr_a = a.begin(); itr_a != a.end(); itr_a++)
		for (typename list<T>::const_iterator itr_b = b.begin(); itr_b != b.end(); itr_b++)
			if (*itr_a == *itr_b)
				temp.push_back(*itr_a);

	return temp;
}

template <class T>
list<T> unordered_union(const list<T> & a, const list<T> & b)
{
	list<T> temp_a = a;
	selection_sort(temp_a);
	list<T> temp_b = b;
	selection_sort(temp_b);

	return ordered_union(temp_a,temp_b);
}

template <class T>
list<T> unordered_intersect(const list<T> & a, const list<T> & b)
{
	// list<T> temp_a = a;
	// selection_sort(temp_a);
	// list<T> temp_b = b;
	// selection_sort(temp_b);
	//
	// cout << "1st list sorted = ";
	// for (list<int>::iterator itr = temp_a.begin(); itr != temp_a.end(); itr++)
	// 	cout << *itr << " ";
	// cout << endl;
	//
	// cout << "2nd list sorted = ";
	// for (list<int>::iterator itr = temp_b.begin(); itr != temp_b.end(); itr++)
	// 	cout << *itr << " ";
	// cout << endl;

	//return ordered_intersect(temp_a, temp_b);
	return ordered_intersect(a, b);
}

int main()
{
	int list_1 [] = {4, 8, 15, 12, 9, 3, 20, 5};
	list<int> l1(list_1, list_1+8);
	int list_2 [] = {9, 5, 27, 33, 4, 19, 2, 14, 95, 18};
	list<int> l2(list_2, list_2+10);

	cout << "l1 = ";
	for (list<int>::iterator itr = l1.begin(); itr != l1.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "l2 = ";
	for (list<int>::iterator itr = l2.begin(); itr != l2.end(); itr++)
		cout << *itr << " ";
	cout << endl << endl;

	list<int> l3 = unordered_intersect(l1, l2);

	cout << "l1 ∩ l2 = ";
	for (list<int>::iterator itr = l3.begin(); itr != l3.end(); itr++)
		cout << *itr << " ";
	cout << endl << endl;

	list<int> l4 = unordered_union(l1, l2);

	cout << "l1 ∪ l2 = ";
	for (list<int>::iterator itr = l4.begin(); itr != l4.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	int list_5 [] = {4, 8, 15, 12, 9, 3, 20, 5};
	list<int> l5(list_5, list_5+8);
	int list_6 [] = {9, 5, 27, 33, 4, 19, 2, 14, 95, 18};
	list<int> l6(list_6, list_6+10);



}
