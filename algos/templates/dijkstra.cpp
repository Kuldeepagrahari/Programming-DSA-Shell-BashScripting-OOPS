vector<int > djikshtra ( int n, vector<vector<int>> &edges ) {
    int V = n;
 	vector<pair<int,int>> adj[V];
	for (auto it : edges) {
		adj[it[0]].push_back({it[1],it[2]});
        // adj[it[1]].push_back({it[0],it[2]});
	}

      vector<int> dist(V);
      for ( int i = 0 ;i < V; i++ ) dist[i] = 1e5+1;
    //  cout << dist[2];
      int parent[V];
      for ( int i =0 ; i< V; i++ )parent[i] = i;
    //   djikshtra(dist,parent,adj);
       priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //   {w ,u}
      dist[0] = 0;
      pq.push({0,0});
      while ( !pq.empty()){
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();
      for ( auto sam : adj[node]){
        int w2 = sam.second;
        int v = sam.first;
        // cout<<w2<<" "<<v;
         if ( dist[v] > dis + w2 ){
              dist [ v ] =  dis + w2 ;
              pq.push({dis + w2, v});
              parent[v] = node;
         }
      }
      }
      for ( int i = 0; i < V; i++ ){
          if ( dist[i] == 1e5+1 ) dist[i] = -1;
      }
      return dist;
}
