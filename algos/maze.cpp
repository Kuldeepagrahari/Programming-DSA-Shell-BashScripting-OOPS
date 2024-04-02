#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
  void finder ( vector<vector<int>> &m, int n, int row,int col ,  vector<vector<int>>&vis, string path, vector<string>&ans){
        
        if ( row == n-1 && col == n-1 ){
            ans . push_back( path );
            return;
        }
        
        
        // D,L,R,U
        //D
        if ( row + 1 < n && !vis[row+1][col] && m[row+1][col] == 1 ){
            vis[row][col] = 1;
            finder ( m ,n , row+1, col, vis, path+'D', ans );
            vis[row][col] = 0;
        }
        
        // L
        if ( col - 1 >= 0 && !vis[row][col - 1] && m[row][col-1] == 1 ){
            vis[row][col] = 1;
            finder ( m ,n , row , col - 1 , vis, path+'L', ans );
            vis[row][col] = 0;
        }
        //R
        if ( col + 1 < n && !vis[row][col+1] && m[row][col+1] == 1 ){
            vis[row][col] = 1;
            finder ( m ,n , row, col + 1, vis, path+'R', ans );
            vis[row][col] = 0;
        }
        //U
        if ( row - 1 >= 0  && !vis[row-1][col] && m[row-1][col] == 1 ){
            vis[row][col] = 1;
            finder ( m ,n , row - 1, col, vis, path+'U', ans );
            vis[row][col] = 0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
    
        vector<vector<int>> vis( n, vector<int> (n,0) );
        vector<string>ans;
        
        string path = "";
        if (m[0][0] == 1 )finder( m , n , 0, 0 , vis, path, ans );
        return ans;    
    }
    };
    int main(){
        int n = 4;
        vector<vector<int>> m={{1,0,0,0},{1,1,0,1},{1,1,0,1},{0,1,1,1}};
        Solution obj;

        vector<string> ans = obj.findPath(m,n);
        for (auto&sam:ans){
            cout << sam << endl;
        }
        // O(4^(n^2))

    }