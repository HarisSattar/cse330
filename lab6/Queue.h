/*******************************************************************************************
* Haris Sattar
* Queue.h
* 2/24/16
* header file for Queue
*******************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

// Queue.h  -- a queue implemented as an adapter (of vector or list or ...)

#include "../lab5/List.h"

using namespace std;

template <class T, template <class T> class Container = List>
class Queue
{
public:
    bool empty() const { return container.empty(); };
    unsigned int size() const { return container.size(); }
    void push(const T & x) { container.push_back(x); }
    void pop() { container.pop_front(); }
    T & front() { return container.front(); }
    T & back() { return container.back(); }


private:
    Container<T> container;
};

#endif
