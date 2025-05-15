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

double K(vector<double>& a, vector<vector<double>> &dp, int ind, int heads){
    if(ind == a.size()) {
        int tails = a.size() - heads;
        if(heads > tails) return 1.0;
        else return 0.0;
    }
    if(dp[ind][heads] != -1) return dp[ind][heads];
    double t = 0.0, h = 0.0;
    h = a[ind] * K(a, dp, ind + 1, heads + 1);
    t = (1 - a[ind]) * K(a, dp, ind + 1, heads);
    return dp[ind][heads] = h + t;


}
 
void solve()
{
    int n, m;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
    double ans = K(v, dp, 0, 0);
    cout << fixed << setprecision(9) << ans << endl;


 
    
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve();
 
    return 0;
}