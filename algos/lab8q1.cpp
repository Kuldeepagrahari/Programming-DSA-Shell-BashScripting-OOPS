#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define N 8

typedef pair<int, int> pii;

void shortestDist(vector<pii> adj[], int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(N, INF);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        if (u_dist > dist[u])
            continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout <<  dist[N - 1];
}

int main() {
    int n;
    cin >> n;
    vector<pii> adj[n];

    vector<vector<int>>edges(n,vector<int>(3));
    // u,v,w
    int edg;
    cin >> edg;

    for ( int i = 0; i <edg; i++ ){
        cin >> edges[i][0];
        cin >> edges[i][0];
        cin >> edges[i][2];
        // adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    for ( int i = 0; i< edg; i++ ){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    shortestDist(adj,n);
    
   
}
