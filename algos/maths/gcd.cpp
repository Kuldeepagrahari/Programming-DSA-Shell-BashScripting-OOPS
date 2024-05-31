#include<bits/stdc++.h>
using namespace std;

int GCD ( int x, int y ){
    if ( x == 0 ){
        return y;
    }

    return GCD(y%x , x);
}

int main() {
    cout << GCD(8,12);
}