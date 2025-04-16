#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n";

// int K(vector<int> &a, int prev, int prevprev, int ind){
//     if(ind == a.size()) return 0;

//     int one = 0, two = 0;

//     one = abs(a[ind] - prev) + K()

// }

void solve()
{
    int n, m, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;
    vector<int> dp(n + 1, 0);
    // dp[i] : min cost to reach i

    int one = INT_MAX, two = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                mini = min(abs(a[i] - a[i - j]) + dp[i - j], mini);
            }
        }
        dp[i] = mini;
    }
    cout << dp[n - 1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
