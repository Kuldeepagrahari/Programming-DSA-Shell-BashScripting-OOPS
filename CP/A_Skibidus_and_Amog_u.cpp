#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while ( t-- ){
        string s;
        cin >> s;
        string p;
        int l = s.length();
        for ( int i = 0; i < l - 2; i++ ){
            p += s[i];
        }
        p += 'i';
        cout << p << endl;
    }
}