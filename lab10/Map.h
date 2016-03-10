#ifndef MAP_H
#define MAP_H

// Map.h

#include <set>
#include "Pair.h"

using namespace std;

template < class key, class value >
class Map : public Set < Pair < key, value > >
{
public:
   typedef Set <Pair <key, value> > parent;
   typedef Set_iterator <Pair <key, value> > iterator;

   Map(): parent() {}

   iterator find(const key & k);
   value & operator[](const key & k);
   void erase(const key & k);
};

// your code goes here
template <class key, class value>
typename Map<key, value>::iterator Map<key, value>::find(const key & k)
{
    value_type test;
    test.first = k;
    return parent::find(test);
}

template <class key, class value>
void Map<key, value>::erase(const key & k)
{
    iterator where = find(k);
    if (where != end())
        erase(where);
}

template <class key, class value>
value & Map<key, value>::operator[](const key & k)
{
    value_type test;
    test.first = k;
    pair<iterator, bool> where = insert(test);
    return (*(where.first)).second;
}

#endif
