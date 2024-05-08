

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        int  m = edges.size();
        vector<int> vis(n,0);
        vector< pair < int ,int > > adj[n];
        for ( int i = 0; i< m ; i++ ){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
             adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
           

        vector<int> dist( n , 1e5+1 );   
        priority_queue< pair<int, int >, vector<pair<int, int >>,greater<pair<int,int>> > pq;

        pq.push({0 , 0 });
        dist[0] = 0;
        while ( !pq.empty() ){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
             
             // tle remover
             if ( vis[node] )continue;
             vis[node] = 1;

             
            for ( auto it: adj[node] ){
                int w = it.second;
                int v = it.first;

            
                if ( dist[v] > dis + w && dis+w < disappear[v] ){
                      dist[v] = dis + w;
                      pq.push({ dis + w , v});
                    
                    
                }
            }
        }

        for ( int i = 0; i <  n ; i++ ){
            if ( dist[i] >= disappear[i] )dist[i] = -1;
        }
        return dist;



    }
};