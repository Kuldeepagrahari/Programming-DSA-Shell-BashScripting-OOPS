#include <iostream>
using namespace std;
void prints(int &x){
    cout << &x;
}

int main() {
   int x = 8;
   int *ptr ;
   ptr = &x;
   cout << *ptr;
   prints(x);


    return 0;
}
