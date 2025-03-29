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
}
const int N = 105, inf = 1e9 + 7;
int n, x;
int c[N];

int dp[N][1000000 + 6];
int f(int i, int koto) {
    if(koto < 0) return 0;
    if(i >= n) {
        if(!koto) return 1;
        return 0;
    }

    int &ans = dp[i][koto];
    if(~ans) return ans;
    ans = 0;
    ans += f(i + 1, koto);
    ans %= mod;
    ans += f(i, koto - c[i]);
    ans %= mod;
    

    return ans;
}

void solve()
{
    // int n, m;
    // cin >> n >> m;

    // vector<int> a(n);
   
    // for (int &x : a)
    //     cin >> x;

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // // base case
    // for(int i = 1; i <= n; i++) dp[0][i] = 1;
    // // take or not take
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++){
    //         if(i - a[j - 1] >= 0) dp[i][j] = dp[i - a[j - 1]][j] + dp[i][j - 1];
    //         else dp[i][j] = dp[i][j - 1];
    //     }
    // }
    // cout << dp[m][n] << endl;



    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> c[i];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            dp[i][j] = -1;
        }
    }

    for(int i = n; i >= 0; i--) {
        for(int koto = 0; koto <= x; koto++) {
                int &ans = dp[i][koto];

                // if(koto < 0) return 0;
                if(i >= n) {
                    if(!koto) ans = 1;
                    else ans = 0;
                    continue;
                }

                ans = 0;
                ans += dp[i + 1][koto];
                ans %= mod;
                // ans += f(i, koto - c[i]);
                if(koto - c[i] >= 0) ans += dp[i][koto - c[i]];
                ans %= mod;
                
        }
    }

    // f(0, x);
    // cout << f(0, x) << '\n'; 
    // cout << dp[n][0] << '\n'; 

    cout << dp[0][x] << '\n'; 

    // for(int i = 0; i <= x; i++) {
    //     cout << dp[n - 1][i] << ' ';
    // }

}
// 1 0 0 0 0 1 0 0 -1 0 
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
