#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int dfs(vector<vector<int>>& adj,int vis[],int node ){
        vis[node]=1;
        int cnt = 1;
        for ( auto v: adj[node]){
            if(!vis[v]){
                cnt += dfs(adj,vis,v);
            }
        }
        return cnt;   
        
  }
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for ( int i=0; i < m; i++ ){
        int u,v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    int vis[n+1]={0};
    int ans=0;
    for ( int i=1;i <= n;i++ ){
        if( !vis[i]){
            ans=max(ans,dfs(adj,vis,i));
        }
    }
    cout << ans <<endl;

}