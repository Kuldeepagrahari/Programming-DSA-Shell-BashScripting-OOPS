#include<bits/stdc++.h>
using namespace std;

int main(){

   int t;
   cin >> t;

   while ( t-- ){
    string s;

    cin >> s;
    int l = s.length();
    int f = 0;
    for ( int i = 0; i < l - 1  ; i++ ){
        if ( s[i] == '0' && s[i+1] == '1' ){
            f = 1;
            break;
        }
    }
   
    int c = 0;
   for ( int i = 0 ;i < l  - 1; i++ ){
    if ( s[i] != s[i+1] )c++;
   }

   cout << c - (f == 1) + 1 << endl;
    
    
}
}

