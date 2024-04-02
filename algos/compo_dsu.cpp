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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        DSU obj(n);
        int extraEdges = 0;
        for ( int i = 0; i< edges ;i ++ ){
            int u = connections[i][0];
            int v = connections[i][1];
            if ( obj.find_ulp(u) == obj.find_ulp(v) ){
                 extraEdges++;
            }
            else {
                obj.unionBySize(u,v);
            }
        }
         
         int componentsOfGraph = 0;
        for ( int i = 0; i< n ;i ++ ){
            if ( obj.find_ulp(i) == i ){
                componentsOfGraph ++;
            }
        }

        if ( extraEdges >= componentsOfGraph - 1 ){
            return componentsOfGraph -1;
        }
        return -1;
    }
};