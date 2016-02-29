#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double-ended queue

#include <vector>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque {
public:
	typedef DequeIterator<T> iterator;
	
	Deque(): vec_one(), vec_two() { }
	Deque(const unsigned int size, const T& initial): vec_one(size/2, initial), vec_two(size-(size/2), initial) { }
	Deque(const Deque<T> & d): vec_one(d.vec_one), vec_two(d.vec_two) { }
    ~Deque() { } // destructors for vecOne and vecTwo are automatically called
                 // never call a destructor explicitly
    Deque & operator=(const Deque<T> & d);

	T & operator[](unsigned int);
	T & front();
	T & back();
	bool empty();
	iterator begin();
	iterator end();
	void erase(const iterator &);
	void erase(const iterator &, const iterator &);
	void insert(const iterator &, const T &);
	int size();
	void push_front(const T & value);
	void push_back(const T & value);
	void pop_front();
	void pop_back();
protected:
	vector<T> vec_one;
	vector<T> vec_two;
};

template <class T>
Deque<T> & Deque<T>::operator=(const Deque<T> & d)
{
	vec_one = d.vec_one;
	vec_two = d.vec_two;
}

template <class T>
T & Deque<T>::operator[](unsigned int index)
{
	int n = vec_one.size();
	
	if (index <= n)
		return vec_one[(n - 1) - index];
	else
		return vec_two[index - n];
}

template <class T>
bool Deque<T>::empty()
{
	return vec_one.empty() && vec_two.empty();
}

template <class T>
void Deque<T>::push_front(const T & value)
{
	vec_one.push_back(value);
}

template <class T>
void Deque<T>::push_back(const T & value)
{
	vec_two.push_back(value);
}

template <class T>
int Deque<T>::size()
{
	return vec_one.size() + vec_two.size();
}

template <class T>
typename Deque<T>::iterator Deque<T>::begin()
{
	return iterator(this, 0);
}

template <class T>
typename Deque<T>::iterator Deque<T>::end()
{
	return iterator(this, size());
}

// Your code goes here ...

template <class T>
class DequeIterator {
	friend class Deque<T>;
	typedef DequeIterator<T> iterator;
public:
	DequeIterator(): theDeque(0), index(0) { }
	DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
	DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

	T & operator*();
	iterator & operator++();
	iterator operator++(int);
	iterator & operator--();
	iterator operator--(int);
	bool operator==(const iterator & r);
	bool operator!=(const iterator & r);
	bool operator<(const iterator & r);
	T & operator[](unsigned int i);
	void operator=(const iterator & r);
	iterator operator+(int i);
	iterator operator-(int i);
protected:
	Deque<T> * theDeque;
	int index;
};

template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator++(int)
{
	
}

template <class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator++()
{
	++index;
	return *this;
}

template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator--(int)
{
	
}

template <class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator--()
{
	--index;
	return *this;
}

template <class T>
bool DequeIterator<T>::operator==(const DequeIterator<T>::iterator & r)
{
	return theDeque == r.theDeque && index == r.index;
}

template <class T>
bool DequeIterator<T>::operator!=(const DequeIterator<T>::iterator & r)
{
	return theDeque != r.theDeque && index != r.index;
}

template <class T>
bool DequeIterator<T>::operator<(const DequeIterator<T>::iterator & r)
{
	return theDeque == r.theDeque && index < r.index;
}

template <class T>
void DequeIterator<T>::operator=(const DequeIterator<T>::iterator & r)
{
	theDeque == r.theDeque;
	index == r.index;
}

template <class T>
T & DequeIterator<T>::operator*()
{
	return (*theDeque)[index];
}

#endif
