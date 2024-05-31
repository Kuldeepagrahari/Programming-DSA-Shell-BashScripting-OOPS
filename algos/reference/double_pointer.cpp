#include<bits/stdc++.h>
using namespace std;

class Person{
   
};

void swapper(Person **obj1, Person **obj2)
{
    // double pointers means pointer to  a pointer pointing a identifier
    
   Person *t = *obj2;
   *obj2 = *obj1;
   *obj1 = t; 
}