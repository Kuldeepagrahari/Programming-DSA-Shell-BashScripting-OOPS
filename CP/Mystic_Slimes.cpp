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

    vector<int> v(n);
    for ( int i = 0; i < n ; i ++ )cin >> v[i];
    int occ = 0;
    int maxi = *max_element(v.begin(), v.end());
    for ( int i = 0 ; i < n ; i ++ )if ( v[i] == maxi ) occ++;
    int f = -1;
    for ( int i = 0 ; i < n; i++ ){
        if ( v[i] == maxi ) {
            f = i;
            break;
        }
    }
    int l = -1;
    for ( int i = n-1; i >= 0; i-- ){
         if ( v[i] == maxi ) {
            l = i;
            break;
        }
    }
    int left = 0, right = 0;
    if ( f == 1 ) left += v[0];
    if ( l == n - 2 ) right += v[n - 1];
    

    int ans = 0;
    if ( occ == 1 ){
        ans = maxi - left - right;
    }else{
        int lefty = 0, righty = 0;
        if ( f == 1 ) lefty += v[0];
        if ( n - f - 1 == 1 )righty += v[n-1];

        int rlefty = 0, rrighty = 0;
        if ( l == n - 2 ) rrighty += v[n-1];
        if ( l == 1 ) rlefty += v[0];

        int ans1 = maxi - lefty - righty;
        int ans2 = maxi - rlefty - rrighty;
        ans = max(ans1, ans2);
    }
    cout << ans << endl;
    }
}
