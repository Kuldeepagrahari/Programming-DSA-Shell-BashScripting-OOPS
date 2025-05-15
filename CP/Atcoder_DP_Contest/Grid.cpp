#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int K(vector<string> &grid, vector<vector<int>> &dp, int i, int j){
    if(i == grid.size() - 1 && j == grid[0].size() - 1) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int right = 0, down = 0;
    if(i + 1 < grid.size() && grid[i + 1][j] == '.')  
        down = K(grid, dp, i + 1, j) % mod;
    if(j + 1 < grid[0].size() && grid[i][j + 1] == '.')
        right = K(grid, dp, i, j + 1) % mod;
    return dp[i][j] = (right + down) % mod;
    
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
       cin >> grid[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = K(grid, dp, 0, 0);
    cout << ans << endl;
}