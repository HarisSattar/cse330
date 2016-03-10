#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// Priority_queue.h  -- a priority_queue implemented as a heap

#include "../lab4/Vector.h"

using namespace std;

template <class T>
class Priority_queue {
public:
   Priority_queue() : c() { }
   Priority_queue(const Priority_queue & p): c(p.c) { }
   Priority_queue & operator=(const Priority_queue & p) { c = p.c; return *this; }
   // vector destructor is automatically called when an obj of type Priority_queue is destroyed

   bool empty() { return c.empty(); }
   unsigned int size() { return c.size(); }
   void push(const T & x);
   void pop();
   T & top() { return c.front(); }
private:
   Vector<T> c;
};

template <class T>
void adjust_heap(T start, unsigned heapSize, unsigned position)
{
    while (position < heapSize) {
        unsigned childpos = position * 2 + 1;
        if (childpos < heapSize) {
            if ((childpos + 1 < heapSize) && start[childpos + 1] > start[childpos])
                childpos++;
            if (start[position] > start[childpos])
                return;
            else
                swap(start[position], start[childpos]);
        }
        position = childpos;
    }
}

template <class T>
void push_heap(T start, T stop)
{
    unsigned position = (stop - start) - 1;
    unsigned parent = (position - 1) / 2;

    while (position > 0 && start[position] > start[parent]) {
        swap(start[position], start[parent]);
        position = parent;
        parent = (position - 1) / 2;
    }
}

template <class T>
void pop_heap(T start, T stop)
{
    unsigned lastPosition = (stop - start) - 1;
    swap(start[0], start[lastPosition]);
    adjust_heap(start, lastPosition, 0);
}

// your code goes here ...
template <class T>
void Priority_queue<T>::push(const T & x)
{
    c.push_back(x);
    push_heap(c.begin(), c.end());
}

template <class T>
void Priority_queue<T>::pop()
{
    pop_heap(c.begin(), c.end());
    c.pop_back();
}

#endif
