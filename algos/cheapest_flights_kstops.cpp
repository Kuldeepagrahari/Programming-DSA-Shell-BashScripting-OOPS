
#include <bits/stdc++.h>
using namespace std;

int dijkstra(int n, vector<vector<int>> &edges, int k, int dst, int src)
{
    int V = n;
    vector<pair<int, int>> adj[V];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> dist(V);
    for (int i = 0; i < V; i++)
        dist[i] = 1e5 + 1;
    queue<pair<int, pair<int, int>>> pq;
    // priority_queue ki jarurat nhi h kyuki jaise hamne dijkstra ka pehla problem kiya tha 
    // jisme weighted graph nhi tha har edge ka weight 1 tha,  same here ham weight ke hisab se 
    // queue me nhi daal sakte kyuki kuch path aise honge jo jada dist wale honge but kam stops le
    // rahe honge to jada better hai hum sabse kam stops wale node ko pehle chunege
    //   {w ,u}
    dist[src] = 0;

    pq.push({0, {0, src}}); // k,w,src

    while (!pq.empty())
    {
        auto it = pq.front();
        int nk = it.first;
        int dis = it.second.first;
        int node = it.second.second;
        pq.pop();

        if (nk <= k)
        {
            for (auto sam : adj[node])
            {
                int w2 = sam.second;
                int v = sam.first;

                if (dist[v] > dis + w2)
                {
                    dist[v] = dis + w2;
                    pq.push({nk + (v != dst), {dis + w2, v}});
                }
            }
        }
    }
    if (dist[dst] == 100001)
        return -1;
    return dist[dst];
}



int main()
{
     int n,dst,src,k;
     vector<vector<int>> flights(n,vector<int>(2));
    dijkstra(n, flights, k, dst, src);
}