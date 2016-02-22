// Ques_test.cpp

#include <iostream>
#include <cassert>
#include "Queue.h"
#include "../lab3/String.h"
#include "../lab5/List.h"

using namespace std;

int main()
{
   Queue<int, List> q1;
   assert(q1.size() == 0);
   assert(q1.empty());

   q1.push(16);
   assert(q1.size() == 1);
   assert(q1.front() == 16);

   q1.pop();
   assert(q1.size() == 0);

   q1.push(11);
   assert(q1.size() == 1);
   assert(q1.back() == 11);

   q1.push(22);
   assert(q1.size() == 2);
   assert(q1.front() == 11);

   q1.push(33);
   assert(q1.size() == 3);
   assert(q1.front() == 11);

   q1.pop();
   assert(q1.size() == 2);
   assert(q1.front() == 22);
   assert(q1.back() == 33);

   Queue<String, List> q2;
   q2.push("abc");
   q2.push("de");
   q2.pop();
   assert(q2.front() == "de");

   cout << "SUCCESS\n";
}
