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
 
  
vector<int> dp;
int K(vector<int>& a, vector<int> &dp, int ind, int sum){
    if(sum == 0) return 1;
    if(ind == a.size()) return 0;
    if(dp[sum] != -1) return dp[sum];
 
    int t = 0, nt = 0;
    
    if(sum - a[ind] >= 0) t = K(a, dp, ind, sum - a[ind]) % mod;
    nt = K(a, dp, ind + 1, sum) % mod;
    cout << "s";
    return dp[sum] = (t + nt) % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> a(n);
   
    for (int &x : a)
        cin >> x;
 
    dp.resize(m + 1, -1);
    cout << K(a, dp, 0, m) << endl;
    // base case
    // for(int i = 0; i <= n; i++) dp[0][i] = 1;
    // // take or not take
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++){
    //         if(i - a[j - 1] >= 0) dp[i][j] = (dp[i - a[j - 1]][j] + dp[i][j - 1]) % mod;
    //         else dp[i][j] = dp[i][j - 1] % mod;
    //     }
    // }
    // cout << dp[m][n] % mod << endl;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 2;
    // cin >> t;
    while (t--)
        solve();
 
    return 0;
}