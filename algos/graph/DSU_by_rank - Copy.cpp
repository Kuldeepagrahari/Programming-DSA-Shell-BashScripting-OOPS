#include <bits/stdc++.h>
using namespace std;
// ulp == ultimate parent
class DSU {
     vector <int> rank , parent;
public:
       // constructor
       DSU ( int n ){
            rank.resize( n+1 , 0);
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

       void unionByRank( int u, int v ){
              int ulp_u = find_ulp ( u );
              int ulp_v = find_ulp ( v );

              if ( ulp_u == ulp_v )return ;

              if ( rank[ulp_v] < rank[ulp_u] ){
                parent[ulp_v] = ulp_u;
              }
              else if ( rank[ulp_v] > rank[ulp_u] ){
                 parent[ulp_u] = ulp_v;
              }
              else{
                 parent[ulp_v] = ulp_u;
                 rank[ulp_u]++;
                 }
            }
    
};
int main()
{
    DSU ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if ( ds.find_ulp(3) == ds.find_ulp(7) )cout << "same\n";
    else cout << "not same \n";
    ds.unionByRank(3,7);
     if ( ds.find_ulp(3) == ds.find_ulp(7) )cout << "same\n";
    else cout << "not same \n";



}
