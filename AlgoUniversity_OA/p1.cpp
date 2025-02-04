#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int t;
    cin >> t;
     while ( t-- ){
       int n;
       cin >> n;
       int m, k;
       cin >> m >> k;
       string s;
       cin >> s;
       int c0 = 0;
       int ans = 0;
       for ( int i = 0 ; i < n; i++ ){
        if ( s[i] == '0')c0++;
        else c0 = 0;
        if ( c0 == m ){
            i += (k-1);
            ans ++;
            c0 = 0;
        }
       }cout << ans << endl;
     }
}