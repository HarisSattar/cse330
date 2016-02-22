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
T & operator[](unsigned int index)
{
	int n = vec_one.size();
	
	if (index < n)
		return vec_one[(n - 1) - index];
	else
		return vec_two[index - n];
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
	iterator operator=(const iterator & r);
	iterator operator+(int i);
	iterator operator-(int i);
protected:
	Deque<T> * theDeque;
	int index;
};
#endif
