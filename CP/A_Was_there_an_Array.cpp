#include <bits/stdc++.h>
using namespace std;
#define int long long

// bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
//     if (a.first != b.first) 
//         return a.first > b.first; 
//     return a.second < b.second;  
// }

signed main() {
   int t;
   cin >> t;

   while ( t-- ){
    int n;
    cin >> n;

    vector<int> v(n - 2);
  
    for ( int i = 0 ; i < n - 2 ; i ++ )cin >> v[i];
    int f = 1;
    for ( int i = 0 ; i < n - 4; i++ ){
        if ( v[i] == 1 && v[i+1] == 0 && v[i+2] == 1)f = -1;
    }
    if ( f == 1 )cout << "YES\n";
    else cout << "NO\n";
   }
}
