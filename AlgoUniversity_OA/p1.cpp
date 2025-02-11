#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int t;
    cin >> t;
     while ( t-- ){
       int n;
       cin >> n;
       vector<int> v(n);
       vector<int> v2(n);
       for ( int i = 0 ;i  < n ; i ++ ) cin >> v[i];
       for ( int i = 0 ;i  < n ; i ++ ) cin >> v2[i];

       sort ( v.begin(), v.end());
       sort ( v2.begin(), v2.end(), greater<int>());

       set<int> st;
       for ( int i = 0 ;i  < n ; i ++ ) {
        for ( int j = 0 ; j < n ; j ++ ){
          st.insert(v[i] + v2[j]);
        }
       }
       if ( st.size() >= 3 )cout << "YES\n";
       else cout << "NO\n";

     }
}