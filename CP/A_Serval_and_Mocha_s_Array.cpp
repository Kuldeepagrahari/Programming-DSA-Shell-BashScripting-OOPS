#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while ( t-- ){
       int n;
       cin >> n;
       
       vector<int> v(n);
       for ( int i  = 0 ;i  < n ; i ++ )cin >> v[i];
       int f = -1;
      for ( int i = 0 ; i < n; i++ ){
        for ( int j = 0 ; j < n && j != i; j++ ){
            if ( __gcd(v[i], v[j]) == 1 || __gcd(v[i], v[j]) == 2) f = 1;
        }
      }
      if ( f == -1 )cout << "NO\n";
      else cout << "YES\n";
    

        
    }
}