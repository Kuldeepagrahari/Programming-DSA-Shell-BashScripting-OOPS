#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, x;
    cin >> r >> x;
    if(x == 2){
        if(r >= 1200 && r <= 2399) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(r >= 1600 && r <= 2999) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}