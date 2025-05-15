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

int K(vector<string>& mat, vector<vector<int>> &dp, int i, int j, int n, int m){
    if(i == n - 1 && j == m - 1) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];

    int x[] = {1, 0};
    int y[] = {0, 1};

    int ways = 0;
  
    for(int k = 0; k < 2; k++){
      int ni = i + x[k];
      int nj = j + y[k];
      if(ni < n && nj < m) {
        if(mat[ni][nj] == '.'){
            ways = (ways + K(mat, dp, ni, nj, n, m)) % mod;
        }
      }
    }
    return dp[i][j] = ways % mod;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) cin >> mat[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = K(mat, dp, 0, 0, n, m);
    cout << ans << endl;
 
    
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve();
 
    return 0;
}