/*******************************************************************************************
 * Haris Sattar
 * Deque.h
 * 2/20/16
 * header file for Deque
 *******************************************************************************************/
#ifndef DEQUE_H
#define DEQUE_H

#include <vector>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque {
public:
    typedef DequeIterator<T> iterator;

    Deque() : vec_one(), vec_two() { }
    Deque(const unsigned int size, const T& initial) : vec_one(size / 2, initial), vec_two(size - (size / 2), initial) { }
    Deque(const Deque<T> & d) : vec_one(d.vec_one), vec_two(d.vec_two) { }
    ~Deque() { } // destructors for vecOne and vecTwo are automatically called
                 // never call a destructor explicitly
    Deque<T> & operator=(const Deque<T> & d);

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

// assignment operator
template <class T>
Deque<T> & Deque<T>::operator=(const Deque<T> & d)
{
    vec_one = d.vec_one;
    vec_two = d.vec_two;
    return *this;
}

// indexing operator
template <class T>
T & Deque<T>::operator[](unsigned int index)
{
    int n = vec_one.size();

    if (index < n)
        return vec_one[(n - 1) - index];
    else
        return vec_two[index - n];
}

// returns the value of the first element
template<class T>
T & Deque<T>::front()
{
    if (vec_one.empty())
        return vec_two.front();
    else
        return vec_one.back();
}

// returns the value of the last element
template<class T>
T & Deque<T>::back()
{
    if (vec_two.empty())
        return vec_one.front();
    else
        return vec_two.back();
}

// returns true if empty
template <class T>
bool Deque<T>::empty()
{
    return vec_one.empty() && vec_two.empty();
}

// adds an element to the beginning of the deque
template <class T>
void Deque<T>::push_front(const T & value)
{
    vec_one.push_back(value);
}

// adds an element to the edn of the deque
template <class T>
void Deque<T>::push_back(const T & value)
{
    vec_two.push_back(value);
}

// removes the first element
template<class T>
void Deque<T>::pop_front()
{
    if (vec_one.empty())
        vec_two.erase(vec_two.begin());
    else
        vec_one.pop_back();
}

// removes the last element
template<class T>
void Deque<T>::pop_back()
{
    if (vec_two.empty()) {
        vector<T> temp;
        for (int i = 1; i < vec_one.size(); i++)
            temp.push_back(vec_one[i]);
        vec_one = temp;
    }
    else
        vec_two.pop_back();
}

// deletes the element at the given position
template<class T>
void Deque<T>::erase(const iterator & pos)
{
    int index = pos.index;
    int n = vec_one.size();

    if (index < n)
        vec_one.erase(vec_one.begin() + (n - 1) - index);
    else
        vec_two.erase(vec_two.begin() + index - n);
}

// deletes elements in a given range
template<class T>
void Deque<T>::erase(const iterator & start, const iterator & end)
{
    int start_index = start.index;
    int end_index = end.index;
    int n = vec_one.size();

    if (start_index < n && end_index < n)
        for (iterator i = start, j = end; i != j; i++, start_index++)
            vec_one.erase(vec_one.begin() + (n - 1) - start_index + 1);
    else if (start_index > n && end_index > n)
        for (iterator i = start, j = end; i != j; i++, start_index++)
            vec_two.erase(vec_two.begin() + start_index - n);
    else {
        vec_one.erase(vec_one.begin(), vec_one.begin() + (n - 1) - start_index + 1);
        vec_two.erase(vec_two.begin(), vec_two.begin() + end_index - n);
    }
}

// inserts an element at the given position
template<class T>
void Deque<T>::insert(const iterator & pos, const T & value)
{
    int index = pos.index;
    int n = vec_one.size();

    if (index < n)
        vec_one.insert(vec_one.begin() + (n - 1) - index + 1, value);
    else
        vec_two.insert(vec_two.begin() + index - n, value);
}

// returns the size of the deque
template <class T>
int Deque<T>::size()
{
    return vec_one.size() + vec_two.size();
}

// returns an iterator to the first element
template <class T>
typename Deque<T>::iterator Deque<T>::begin()
{
    return iterator(this, 0);
}

// returns an iterator to the last element + 1
template <class T>
typename Deque<T>::iterator Deque<T>::end()
{
    return iterator(this, size());
}

template <class T>
class DequeIterator {
    friend class Deque<T>;
    typedef DequeIterator<T> iterator;
public:
    DequeIterator() : theDeque(0), index(0) { }
    DequeIterator(Deque<T> * d, int i) : theDeque(d), index(i) { }
    DequeIterator(const iterator & d) : theDeque(d.theDeque), index(d.index) { }

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

// post-increment
template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator++(int)
{
    DequeIterator<T> temp = *this;
    ++(*this);
    return temp;
}

//pre-increment
template <class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator++()
{
    ++index;
    return *this;
}

// post-decrement
template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator--(int)
{
    DequeIterator<T> temp = *this;
    --(*this);
    return temp;
}

// pre-decrement
template <class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator--()
{
    --index;
    return *this;
}

// comparison operator
template <class T>
bool DequeIterator<T>::operator==(const iterator & r)
{
    return theDeque == r.theDeque && index == r.index;
}

// not equal operator
template <class T>
bool DequeIterator<T>::operator!=(const iterator & r)
{
    return !(*this == r);
}

// less than operator
template <class T>
bool DequeIterator<T>::operator<(const iterator & r)
{
    return theDeque == r.theDeque && index < r.index;
}

// assignment operator
template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator=(const iterator & r)
{
    theDeque = r.theDeque;
    index = r.index;
    return *this;
}

// dereference operator
template <class T>
T & DequeIterator<T>::operator*()
{
    return (*theDeque)[index];
}

// increment iterator position by i
template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator+(int i)
{
    for (int j = 0; j < i; j++)
        ++(*this);
    return *this;
}

// decrease iterator position by i
template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator-(int i)
{
    for (int j = 0; j < i; j++)
        --(*this);
    return *this;
}

#endif
