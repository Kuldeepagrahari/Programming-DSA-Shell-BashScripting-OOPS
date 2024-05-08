#include <bits/stdc++.h>
using namespace std;

class DSU
{
  vector<int> size, parent;

public:
  // constructor
  DSU(int n)
  {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int find_ulp(int node)
  { // O(log(n))
    if (parent[node] == node)
      return node;
    else
      return parent[node] = find_ulp(parent[node]);
    // path compression as well as finding the parent
  }

  void unionBySize(int u, int v)
  {
    int ulp_u = find_ulp(u);
    int ulp_v = find_ulp(v);

    if (ulp_u == ulp_v)
      return;

    if (size[ulp_u] >= size[ulp_v])
    {
      size[ulp_u] += size[ulp_v];
      parent[ulp_v] = ulp_u;
    }

    else
    {
      size[ulp_v] += size[ulp_u];
      parent[ulp_u] = ulp_v;
    }
  }
};

int kruskalMST(int n, vector<vector<int>> &edges, vector<pair<int, int>> &mst)
{

  vector<pair<int, pair<int, int>>> edge;
  for (int i = 0; i < edges.size(); i++)
  {
    edge.push_back({edges[i][2], {edges[i][0], edges[i][1]}});
  }

  sort(edge.begin(), edge.end());
  int mstWt = 0;
  DSU ds(n);

  for (auto &it : edge)
  {
    int wt = it.first;
    int u = it.second.first;
    int v = it.second.second;

    if (ds.find_ulp(u) != ds.find_ulp(v))
    {
      mstWt += wt;
      mst.push_back({u, v});
      ds.unionBySize(u, v);
    }
  }
  return mstWt;
}

void pairprinter(vector<pair<int, int>> mst)
{
  for (int i = 0; i < mst.size(); i++)
  {
    cout << mst[i].first << " " << mst[i].second << endl;
  }
  cout << endl;
}
int main()
{

  int m;
  cout << "enter the num of edges : ";
  cin >> m;
  int n;
  cout << "enter the num of nodes : ";
  cin >> n;
  vector<vector<int>> edges;
  vector<pair<int, int>> mst;

  for (int i = 0; i < m; i++)
  {
    // vector<int>v;
    int x, y, z;
    cin >> x >> y >> z;
    edges.push_back({x, y, z});
  }

  cout << "minimum reparation cost: " << kruskalMST(n, edges, mst) << endl;
  cout << "we need to repair following roads" << endl;
  pairprinter(mst);

  // O(E*logE + E*logV)
}