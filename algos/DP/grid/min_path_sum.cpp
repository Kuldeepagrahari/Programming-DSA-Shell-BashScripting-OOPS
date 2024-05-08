class Solution {
public:

       
    int solve ( int ans , int row, int col , int m, int n , vector<vector<int>> &dp , vector<vector<int>>& grid ){
        if (row == m - 1 && col == n - 1 ){
            
            return grid[m-1][n-1];
        }
        
        if ( dp[row][col] != -1 ){return dp[row][col];}

        int right = INT_MAX , down = INT_MAX;
        if ( col + 1 < n )
        right = grid[row][col] + solve ( ans, row, col + 1 , m , n , dp ,grid) ;
        if ( row + 1 < m )
        down = grid[row][col] + solve (ans, row + 1, col , m , n , dp ,grid);
        dp[row][col]= min ( right, down );

        cout << ans ;
        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<int>> dp ( m, vector<int>(n, -1 ));
        return solve ( 0 ,0 , 0 , m , n, dp , grid );
    }
};