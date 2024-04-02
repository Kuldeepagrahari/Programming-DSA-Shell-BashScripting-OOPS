#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int nodes = 0;
        int n = grid.size();

        vector< vector< int >> mat ( n, vector< int > ( n , 1e5 ));
        priority_queue< pair<int, pair<int,int>> , vector<pair<int, pair<int,int>> >, greater< pair<int, pair<int,int>> >> pq;
        if ( grid[0][0] == 0 )
        pq.push( {1, {0,0}} );
         
        int xx[] = { 1, 1, 1, 0 , 0 , -1, -1 , -1 };
        int yy[] = { -1, 0, 1, -1 , 1 , -1 , 0, 1 };
        while ( !pq.empty() ){
               auto it = pq.top();
               int x = it.second.first;
               int y = it.second.second;
               int w = it.first;
               pq.pop();
               
               for ( int i = 0; i < 8 ;i ++ ) {
                int nx = x + xx[i];
                int ny = y + yy[i];
                   if ( nx < n && nx >= 0 && ny < n && ny >= 0 ){
                    if ( grid[nx][ny] == 0 ){
                         if ( mat[ nx ][ ny ] > 1 + w ){
                            mat[nx][ny] = 1 + w;
                            pq.push({1+w, {nx,ny}});
                         }
                    }
                   }
               }

        }
        if ( n == 1 )if ( grid[0][0] == 0 ) return 1;
        if ( mat[n-1][n-1] == 1e5 ) return -1;
        else return mat[n-1][n-1];

    }
};

int main(){
    
}