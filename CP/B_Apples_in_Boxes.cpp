#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int mn = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());
   
    int cnt = count(v.begin(), v.end(), mx);
    // 1 3 3
    if (mx - mn > k + 1 || (mx - mn == k + 1 && cnt > 1))
    {
        cout << "Jerry\n";
        return;
    }

    int check1 = 0;
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum & 1) cout << "Tom\n";
    else cout << "Jerry\n";
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}