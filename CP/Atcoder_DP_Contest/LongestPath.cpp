#include<bits/stdc++.h>
using namespace std;
//here dp itself act as visited array and ensures that each node is calculated once only -> O(N + E) time complexity
int K(vector<vector<int>> &adj, vector<int> &dp, int u){

    if(dp[u] != -1) return dp[u];
    int path = 0;

    for(int v : adj[u]){
        path = max(path, 1 + K(adj, dp, v));
    }
    return dp[u] = path;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<int> dp(n + 1, -1);
    int ans = 0;
    for(int i  = 1; i <= n; i++){
        if(dp[i] == -1){
            ans = max(ans, K(adj, dp, i));
        }
    }
    cout << ans << endl;
}