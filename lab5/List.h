/*******************************************************************************************
 * Haris Sattar
 * List.h
 * 2/20/16
 * header file for List
 *******************************************************************************************/

#ifndef LIST_H
#define LIST_H

// List.h - a doubly-linked list

#include <algorithm>

using namespace std;

// forward declaration of classes defined in this header
template <class T> class Link;
template <class T> class List_iterator;

template <class T>
class List
{
public:
    typedef List_iterator<T> iterator;

    List();
    List(const List<T> & l);
    ~List();

    bool empty() const;
    unsigned int size() const;
    T & back() const;
    T & front() const;
    void push_front(const T & x);
    void push_back(const T & x);
    void pop_front();
    void pop_back();
    iterator begin() const;
    iterator end() const;
    void insert(iterator pos, const T & x); // insert x before pos
    void erase(iterator & pos);             // pos must be valid after erase() returns
    List<T> & operator=(const List<T> & l);

protected:
    Link<T> * first_link;
    Link<T> * last_link;
    unsigned int my_size;
};

// constructor
template <class T>
List<T>::List()
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
}

// copy constructor
template <class T>
List<T>::List(const List & l)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for (Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current -> value);
}

// destructor
template <class T>
List<T>::~List()
{
	Link<T> * first = first_link;
	while (first != 0) {
		Link<T> * next = first -> next_link;
		delete first;
		first = next;
	}
}

// returns an iterator to the first element
template <class T>
typename List<T>::iterator List<T>::begin() const
{
    return iterator(first_link);
}

// returns an iterator to the last element + 1
template <class T>
typename List<T>::iterator List<T>::end() const
{
	return ++iterator(last_link);
}

// returns the size of the list
template <class T>
unsigned int List<T>::size() const
{
    return my_size;
}

// adds element to the back of the list
template <class T>
void List<T>::push_back(const T& x)
{
    Link<T>* new_link = new Link<T>(x);

    if (empty())
        last_link = first_link = new_link;
    else {
		new_link->prev_link = last_link;
        last_link->next_link = new_link;
		last_link = new_link;
    }
    my_size++;
}

// returns true if list is empty
template <class T>
bool List<T>::empty() const
{
    return first_link == 0;
}

// returns the value of the first element
template <class T>
T & List<T>::front() const
{
    return first_link->value;
}

// returns the value of the last element
template <class T>
T & List<T>::back() const
{
    return last_link->value;
}

// adds element to the front of the list
template <class T>
void List<T>::push_front(const T& x)
{
	Link<T>* new_link = new Link<T>(x);

	if (empty())
		first_link = last_link = new_link;
	else {
		first_link->prev_link = new_link;
		new_link->next_link = first_link;
		first_link = new_link;
	}
	my_size++;
}

// adds element before the postiton indicated
template <class T>
void List<T>::insert(iterator pos, const T & x)
{
	if (pos == begin())
		push_front(x);
	else if (pos == end())
		push_back(x);
	else {
		Link<T> * new_link = new Link<T>(x);
		Link<T> * current = pos.current_link;

		new_link->next_link = current;
		new_link->prev_link = current->prev_link;
		current->prev_link = new_link;
		current = new_link->prev_link;

		if (current != 0)
		current->next_link = new_link;
		my_size++;
	}
}

// removes element in the front
template <class T>
void List<T>::pop_front()
{
	Link<T> * save = first_link;
	first_link = first_link->next_link;

	if (first_link != 0)
		first_link->prev_link = 0;
	else
		last_link = 0;

	delete save;
	my_size--;
}

// removes element in the back
template <class T>
void List<T>::pop_back()
{
	Link<T> * save = last_link;
	last_link = last_link->prev_link;

	if (last_link != 0)
		last_link->next_link = 0;
	else
		first_link = 0;

	delete save;
	my_size--;
}

// removes an element from the postiton indicated
template <class T>
void List<T>::erase(iterator & pos)
{
	if (pos == end())
		pop_back();
	else if (pos == begin())
		pop_front();
	else {
		Link<T> * save = pos.current_link;
		save->next_link->prev_link = save->prev_link;
		save->prev_link->next_link = save->next_link;

		delete save;
		my_size--;
	}
}

template <class T>
class Link
{
private:
    Link(const T & x): value(x), next_link(0), prev_link(0) {}

    T value;
    Link<T> * next_link;
    Link<T> * prev_link;

    friend class List<T>;
    friend class List_iterator<T>;
};

template <class T>
class List_iterator
{
public:
    typedef List_iterator<T> iterator;

    List_iterator(Link<T> * source_link): current_link(source_link) { }
    List_iterator(): current_link(0) { }
    List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) { }

    T & operator*();  // dereferencing operator
    iterator & operator=(const iterator & rhs);
    bool operator==(const iterator & rhs) const;
    bool operator!=(const iterator & rhs) const;
    iterator & operator++();  // pre-increment, ex. ++it
    iterator operator++(int); // post-increment, ex. it++
    iterator & operator--();  // pre-decrement
    iterator operator--(int); // post-decrement

protected:
    Link<T> * current_link;

    friend class List<T>;
};

// dereferencing operator
template <class T>
T & List_iterator<T>::operator*()
{
    return current_link -> value;
}

// pre-increment
template <class T>
List_iterator<T> & List_iterator<T>::operator++()
{
    current_link = current_link -> next_link;
    return *this;
}

// assignment operator
template <class T>
typename List_iterator<T>::iterator & List_iterator<T>::operator=(const iterator & rhs)
{
	current_link = rhs.current_link;
}

// post-increment
template <class T>
List_iterator<T> List_iterator<T>::operator++(int)
{
	List_iterator<T> temp = current_link;
	current_link = current_link -> next_link;
	return temp;

}

// equal operator
template <class T>
bool List_iterator<T>::operator==(const iterator & rhs) const
{
	return current_link == rhs.current_link;
}

// not equal operator
template <class T>
bool List_iterator<T>::operator!=(const iterator & rhs) const
{
	return current_link != rhs.current_link;
}

#endif
