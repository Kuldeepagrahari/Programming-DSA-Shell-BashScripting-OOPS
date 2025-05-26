#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int pos1 = a / b * b;
    int pos2 = (a / b + 1) * b;
    int pos3 = (a / b - 1) * b;
    if(abs(a - pos1) <= abs(a - pos2) && abs(a - pos1) <= abs(a - pos3)) {
        cout << a/b << endl;
    } else if(abs(a - pos2) <= abs(a - pos1) && abs(a - pos2) <= abs(a - pos3)) {
        cout << a/b + 1 << endl;
    } else {
        cout << a/b - 1 << endl;
    }
    
}