#include<bits/stdc++.h>
using namespace std;

class DSU {
     vector <int> size , parent;
public:
       // constructor
       DSU ( int n ){
            size.resize( n+1 , 1 );
            parent.resize ( n+1 );
            for ( int i =0 ;i <= n;i ++ ){
                parent[i] = i;
            }
       }
       
       int find_ulp ( int node ){  //O(log(n))
         if ( parent[node] == node )return node;
         else return parent[node] = find_ulp ( parent[node] );
         // path compression as well as finding the parent
       }

       void unionBySize (int u, int v ){
              int ulp_u = find_ulp ( u );
              int ulp_v = find_ulp ( v );  

              if ( ulp_u == ulp_v )return ;

              if ( size[ulp_u] >= size[ulp_v] ){
                size[ulp_u] += size[ulp_v];
                parent[ulp_v] = ulp_u;
              }

              else {
                 size[ulp_v] += size[ulp_u];
                parent[ulp_u] = ulp_v;
              }
        }
};

int distance( vector<int>& p1,  vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int ans(vector<vector<int>>& points) {
    int n = points.size();
    vector<pair<int, pair<int, int>>> edges;

    // o(n^2)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dis = distance(points[i], points[j]);
            edges.push_back({dis, {i, j}});
        }
    }

    // o(nlogn)
    sort(edges.begin(), edges.end());

    
    DSU uf(n);

    int minCost = 0;
    int numEdgesAdded = 0;

    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // If adding the edge doesn't create a cycle, include it in the MST
        if (uf.find_ulp(u) != uf.find_ulp(v)) {
            minCost += weight;
            uf.unionBySize(u, v);
            numEdgesAdded++;
        }

        // Stop when all vertices are connected
        if (numEdgesAdded == n - 1)
            break;
    }

    return minCost;
}

int main() {
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    clock_t start, end;
 

    start = clock();
    cout << ans(points) << endl;  
      end = clock();
 

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    // TC: o(n^2)

}
