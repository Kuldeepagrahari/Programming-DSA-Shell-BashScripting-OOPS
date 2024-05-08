#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int mod = 1e9+7;
template <typename Container>
void printer(const Container &container)
{
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// --------------------------------------------------
template <typename Container>
void pairprint(const Container &container)
{
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

int main(){
    vector<vector<int>> edges = {{0,1,4},{0,6,6},{0,3,5},{0,2,4},{1,2,6},{1,4,3},{1,7,-3},{2,3,1},{2,4,2},{3,6,2},{3,5,5},{4,5,2},{4,7,2},{5,6,3},{5,7,4},{6,7,-6}};
    int n = 8;
  

        int V = n;
 	vector<pair<int,int>> adj[V];
	for (auto it : edges) {
		adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
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
    printer(dist);
}