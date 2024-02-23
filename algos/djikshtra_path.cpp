#include<bits/stdc++.h>
using namespace std;

int djikshtra ( int dist[],int parent[], vector<vector<int>> adj[] ) {
      priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //   {w ,u}

      pq.push({0,0});
      while ( !pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
      for ( auto & sam:adj[node]){
        int w2 = sam[1];
        int v= sam[0];
         if ( dist[v] > dis + w2 ){
              dist [ v ] =  dis + w2 ;
              pq.push({dis + w2, v});
              parent[v] = node;
         }
      }
      }
}
int main(){
    int V = 5;
    // cin >> V;
  
    vector<vector<int>> edges = {{0,1,2},{1,4,5},{1,2,4},{4,2,1},{0,3,1},{3,2,3}};
	vector<pair<int,int>> adj[V];
	for (auto it : edges) {
		adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
	}

      int dist[V]={100000};
     
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
      
      for ( int i =0; i< V;i ++ ){
           cout<<dist[i]<<" ";
      }


}
