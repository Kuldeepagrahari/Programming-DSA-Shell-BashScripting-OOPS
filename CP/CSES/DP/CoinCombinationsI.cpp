#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n";

int K(vector<int>& a, vector<int> &dp, int sum){
    if(sum == 0) return 1;

    if(dp[sum] != -1) return dp[sum];

    int t = 0, nt = 0;
    for(int j = 0; j < a.size(); j++){
        if(sum - a[j] >= 0) t = (t + K(a, dp, sum - a[j])) % mod;
    }
    return dp[sum] = t % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    ll time = 0;
    for (int &x : a)
        cin >> x;


    vector<int> dp(m + 1, -1);
    int ans = K(a, dp, m);
    cout << ans << endl;

    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {

    //     }
    // }
}

int main()
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
