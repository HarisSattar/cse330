#ifndef STACK_H
#define STACK_H

// Stack.h  -- a stack implemented as an adapter (of vector or list or ...)

#include "../lab5/List.h"

using namespace std;

template <class T, template <class T> class Container = List>
class Stack
{
public:
   bool empty() const { return container.empty(); };
   unsigned int size() const { return container.size(); }
   void push(const T & x) { container.push_back(x); }
   void pop() { container.pop_back(); }
   T & top() { return container.back(); }

private:
   Container<T> container;
};

#endif
