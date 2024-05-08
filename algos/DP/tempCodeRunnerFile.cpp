vector<int> cost(V + 1, INT_MAX );
    
    cost[V] = 0;

    for ( int i = V; i >= 1 ; i-- ){
        
        for ( auto it : adj[i] ){
            int c = it.second;
            int v = it.first;
            cost[i] = min ( c + cost[v], cost[i] );
        }
    }

    for ( int i = 1; i <= V; i++ ){
        cout << cost[i] << " "; 
    }