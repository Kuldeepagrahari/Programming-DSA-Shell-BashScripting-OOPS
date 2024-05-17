#include <bits/stdc++.h>
using namespace std;

void dijikstra(vector<vector<int>> edges, int V)
{

    vector<int> adj[V];

    for (int i = 0; i < edges.size(); i++)
    {
        /* The lines `adj[edges[i][0]].push_back(edges[i][2]);` and
        `adj[edges[i][1]].push_back(edges[0][2]);` are adding edges to the adjacency list
        representation of a graph. */
        adj[edges[i][0]].push_back(edges[i][2]);
        adj[edges[i][1]].push_back(edges[0][2]);
    }

    int dist[V];

    for ()
}
int main()
{

    vector<vector<int>> edges = {{1, 2, 1}, {2, 3, 2}, {3, 4, 3}, {4, 5, 4}, {5, 6, 5}};
    int V = 6;

    dijikstra(edges, V);
}