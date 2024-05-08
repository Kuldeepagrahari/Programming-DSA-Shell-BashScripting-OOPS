#include<bits/stdc++.h>
using namespace std;

int main (){
    vector<vector<int>> edges= {{1,2,9},{1,3,7},{1,4,3},{1,5,2},{2,6,4},{2,7,2},{2,8,1},{3,6,2},{3,7,7},{4,8,11},{5,7,11},{5,8,8},{6,9,6},{6,10,5},{7,9,4},{7,10,3},{8,10,5},{8,11,6},{9,12,4},{10,12,2},{11,12,5}};
    
    int edg = edges.size();
    int V = 12; 

    vector<pair<int,int>> adj[V + 1];
    for (int i = 0; i < edg; i++ ){
       adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    // for ( int i = 0; i<= V; i++ )
    // {
    //     for ( int j = 0; j < adj[i].size(); j ++ ){
    //        cout << adj[i][j].first << " " << adj[i][j].second << " ";
    //     }
    //     cout << endl;
    // } 

    vector<int> cost(V + 1, INT_MAX );

    vector<int> best_next_neighbour ( V + 1 );

    
    
    cost[V] = 0;
    best_next_neighbour[V] = V;
    for ( int i = V; i >= 1 ; i-- ){
        
        for ( auto it : adj[i] ){
            int c = it.second;
            int v = it.first;
            if ( c + cost[v] < cost[i] ){
                cost [i] = c + cost[v];
                best_next_neighbour[i] = v;
            }
            // cost[i] = min ( c + cost[v], cost[i] );
        }
    }

    for ( int i = 1; i <= V; i++ ){
        cout << cost[i] << " "; 
   
    }
    cout << endl;
    for ( int i = 1; i <= V ; i++ )     cout << best_next_neighbour[i] << " ";
    
    int st_ind = best_next_neighbour[1];
    int ver = st_ind;
    cout << endl;

    // path
    cout << "1" << " --> ";
    while ( ver != V ){
        cout << ver << " --> " ;
        ver = best_next_neighbour[ver];
    }
    cout << V << endl;

}