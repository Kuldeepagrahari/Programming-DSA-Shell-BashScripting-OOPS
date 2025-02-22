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
        string s;
        cin >> s;
        int ans = 0;
        for ( int i = 0; i < n - 1; i++ ){
            if ( s[i] == '1' && s[i+1] == '0' ) ans+=2;
        }
        if ( s[n-1] == '1') ans++;
        cout << ans << endl;
    }
}
