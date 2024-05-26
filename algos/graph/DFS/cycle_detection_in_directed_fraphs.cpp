  public:
   bool dfs ( int u, vector<int> adj[], vector<int> &vis, 
   vector<int> &callStack ){
        vis[u] = 1;
        callStack[u] = 1;
      
        for ( auto v : adj[u] ){
            // chunki jab ek compo poora hua aur hame cycle nhi mila 
            //to saare vis nodes ko vapas callStack se hatana padega
            // isliye hum return dfs() nhi karenge pehle check karenge ki 
            // usse cycle mil gya h ya nhi , mila tabhi hum return true
            // karenge varna callSatck me false mark karenge
            if ( !vis[v] && dfs(v,adj,vis,callStack)){
                return true;
            }
            else if ( callStack[v] )return true;
        }
        
        callStack[u] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
         vector<int> vis(V, 0);
         vector<int> callStack(V, 0);
        
        for ( int i = 0 ; i< V; i++ ){
            // agar yaha return dfs() krta to isCyclic() pehle
            // compo ke hisab se hi return karke khatam hojata
            // hame har compo ko check krna h
              if ( !vis[i] && dfs(i, adj,vis,callStack )){
                     return true;
            }
        }
        return false; 
    }