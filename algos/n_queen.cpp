#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

bool isSafe ( int row , int col , vector<string> &way ,int n){

   // check upper element
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (way[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (way[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (way[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true; 
}
    void solve ( int n , int col, vector<vector<string>> &ans, vector<string> &way) {

        if( col == n )
        {
           ans.push_back( way );
           return;
        }
        for ( int row = 0; row < n ; row++ ){

             if ( isSafe( row, col , way, n ) ){
                 way[row][col] = 'Q';
                 solve(n,col+1,ans,way);
                 way[row][col] = '.';

             }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> way (n);
        string s(n,'.');
        for ( int i = 0; i< n ;i ++ ){
             way[i] = s;
        }
        
        solve ( n , 0 ,  ans, way );

        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Solution obj;
    
    vector<vector<string>> ans2 =obj.solveNQueens(n);
    for ( int i = 0; i< n ; i++){
    for ( auto&sam:ans2[i]){
         cout << sam << " ";
    }
     cout << endl;
    }

    // o(n!)
}