 void dfs( vector<int> &nodes, vector<int> adj[], int v, vector<int> &vis){
        nodes.push_back(v);
        for ( auto u : adj[v] ){
            if ( !vis[u] ){
                vis[u] = 1;
                dfs(nodes, adj, u, vis );
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
    
        vector<int> vis(V, 0);
        vis[0] = 1;
        
        vector<int> nodes;
        
         dfs(nodes, adj, 0, vis );
         return nodes;
    
        
        
        
    }