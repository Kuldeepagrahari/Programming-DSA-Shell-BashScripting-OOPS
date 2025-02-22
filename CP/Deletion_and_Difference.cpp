#include <bits/stdc++.h>
using namespace std;
#define int long long

// bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
//     if (a.first != b.first)
//         return a.first > b.first;
//     return a.second < b.second;
// }

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
     int n;
     cin >> n;

     map<int, int> mp;
     int f0 = -1;
     for ( int i = 0 ; i < n ; i ++ ){
        int a;
        cin >> a;
        mp[a]++;
        
     }
     int ans = 0;
     for ( auto it : mp ){
        if ( it.first != 0 )
        ans += it.second % 2;
        if ( it.first == 0 ) f0 = 1;
        if ( it.second > 1 ) f0 = 1;
     }
     if ( f0 == 1 ) ans++;
     cout << ans << endl;
    }
}
