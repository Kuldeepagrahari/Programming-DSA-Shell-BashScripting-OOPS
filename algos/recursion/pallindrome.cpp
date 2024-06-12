#include<bits/stdc++.h>
using namespace std;

bool solve ( string s, int ind , int l ){
    if ( ind + 1 > l/2 ) return true;
    else if ( s[ind] != s[l- ind - 1] ) return false;
    return solve(s, ind + 1, l);
}
int main (){
    int t;
    cin >> t;

   while(t--){
     string s ;
    cin >> s;
    if ( solve ( s, 0, s.length() ) )cout << "yes\n";
    else cout << "No\n";
    }
}