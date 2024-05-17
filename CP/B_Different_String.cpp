#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    int t;
    cin >> t;
 
    while ( t--){
       int n ; 
       cin >> n;
       vector<int> v (n-1);

       for ( int i  = 0 ;i < n - 1 ; i ++ ) cin >> v[i] ;

       vector<int> ans (n);
       ans[0] = v[0] + 1;
       ans[1] = ans[0] + v[0];

       for ( int i = 2 ; i< n ; i++) {
             ans[i] = ans[i-1] + v[i-1];

       }

       for ( int i = 0 ; i < n ; i++ )cout << ans[i] << " " ;
       cout << endl; 

       1 5 
       2 7 12
       2 5
    


       
    }
}