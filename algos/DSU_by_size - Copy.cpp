#include <bits/stdc++.h>
using namespace std;
// ulp == ultimate parent
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
int main()
{
    DSU ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if ( ds.find_ulp(3) == ds.find_ulp(7) )cout << "same\n";
    else cout << "not same \n";
    ds.unionBySize(3,7);
     if ( ds.find_ulp(3) == ds.find_ulp(7) )cout << "same\n";
    else cout << "not same \n";



}
