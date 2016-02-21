/*******************************************************************************************
 * Haris Sattar
 * list_functions.cpp
 * 2/14/16
 * Description: Takes two lists and finds the union or the intersect based on if the list is
                ordered or not.
 * Implementation: The sorting algorithm used is selection sort. The ordered_union function
                   uses inplace merge to make the new list. The unordered functions sort
                   the two lists then call the ordered functions.
 * Analysis: The time complexity of the ordered functions are O(n) where n is the size of
             the largest list. The time complexity of the unordered functions are O(n^2)
             where n is the size of the largest list.
 *******************************************************************************************/

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

// sorting algorith for lists
template <class T>
void selection_sort(list<T> & l)
{
    for (typename list<T>::iterator i = l.begin(); i != --(l.end()); i++)
        for (typename list<T>::iterator j = i; j != l.end(); ++j)
            if (*i > *j)
                swap(*i, *j);
} // selection_sort

// returns the union of two lists, lists need to be sorted
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
} // ordered_union

// returns the intersect of two lists, lists need to be sorted
template <class T>
list<T> ordered_intersect(const list<T> & a, const list<T> & b)
{
    list<T> temp;

    typename list<T>::const_iterator itr_a = a.begin();
    typename list<T>::const_iterator itr_b = b.begin();

    while (itr_a != a.end() && itr_b != b.end())
        if (*itr_a < *itr_b)
            ++itr_a;
        else if (*itr_b < *itr_a)
            ++itr_b;
        else {
            temp.push_back(*itr_a);
            ++itr_a;
            ++itr_b;
        }

    return temp;
} // ordered_intersect

// returns the union of two lists, lists do not need to be sorted
template <class T>
list<T> unordered_union(const list<T> & a, const list<T> & b)
{
    list<T> temp_a = a;
    selection_sort(temp_a);
    list<T> temp_b = b;
    selection_sort(temp_b);

    return ordered_union(temp_a,temp_b);
} // unordered_union

// returns the intersect of two lists, lists do not need to be sorted
template <class T>
list<T> unordered_intersect(const list<T> & a, const list<T> & b)
{
    list<T> temp_a = a;
    selection_sort(temp_a);
    list<T> temp_b = b;
    selection_sort(temp_b);

    return ordered_intersect(temp_a, temp_b);
} // unordered_intersect

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
    cout << endl << endl;

    int list_5 [] = {1, 7, 12, 13, 25, 27, 33, 35, 37,};
    list<int> l5(list_5, list_5+9);
    int list_6 [] = {4, 7, 13, 20, 21, 33, 36, 40, 41, 44};
    list<int> l6(list_6, list_6+10);

    cout << "l5 = ";
    for (list<int>::iterator itr = l5.begin(); itr != l5.end(); itr++)
        cout << *itr << " ";
    cout << endl;

    cout << "l6 = ";
    for (list<int>::iterator itr = l6.begin(); itr != l6.end(); itr++)
        cout << *itr << " ";
    cout << endl << endl;

    list<int> l7 = ordered_intersect(l5, l6);

    cout << "l5 ∩ l6 = ";
    for (list<int>::iterator itr = l7.begin(); itr != l7.end(); itr++)
        cout << *itr << " ";
    cout << endl << endl;

    list<int> l8 = ordered_union(l5, l6);

    cout << "l5 ∪ l6 = ";
    for (list<int>::iterator itr = l8.begin(); itr != l8.end(); itr++)
        cout << *itr << " ";
    cout << endl;
} // main
