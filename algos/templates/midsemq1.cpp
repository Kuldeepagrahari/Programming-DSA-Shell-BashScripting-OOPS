
#include<bits/stdc++.h>
using namespace std;
vector<int > djikshtra ( int n, vector<vector<int>> &edges ) {
    int V = n;
 	vector<pair<int,int>> adj[V];
	for (auto it : edges) {
		adj[it[0]].push_back({it[1],it[2]});
        // adj[it[1]].push_back({it[0],it[2]});
	}

      vector<int> dist(V);
      for ( int i = 0 ;i < V; i++ ) dist[i] = 1e5+1;
 
      int parent[V];
      for ( int i =0 ; i< V; i++ )parent[i] = i;
  
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
         cout << dist[i] << " ";
      }
      return dist;
}
//o(eloge)
int main(){
       vector<vector<int>> edges = {{0,1,4},{0,6,6},{0,3,5},{0,2,4},{1,2,6},{1,4,3},{1,7,-3},{2,3,1},{2,4,2},{3,6,2},{3,5,5},{4,5,2},{4,7,2},{5,6,3},{5,7,4},{6,7,-6}};
       int n = 8;

       djikshtra(n,edges);

}