class Solution {
public:

      
    int solve ( int ans , int row, int col , int m, int n , vector<vector<int>> &dp , vector<vector<int>>& grid ){
        if (row == m-1 && col == n-1 ){
            if (grid[row][col] == 1 ) return 0;
            return 1;
        }
        if ( grid[row][col] == 1 )return 0;
        if ( dp[row][col] != -1 ){return dp[row][col];}
        int right = 0 , down = 0;
        if ( col + 1 < n )
        right = solve ( ans, row, col + 1 , m , n , dp ,grid) ;
        if ( row + 1 < m )
        down = solve (ans, row + 1, col , m , n , dp ,grid);
        dp[row][col]= ( right + down );
        cout << ans ;
        return dp[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
          vector<vector<int>> dp ( m, vector<int>(n, -1 ));
        return solve ( 0 ,0 , 0 , m , n, dp ,obstacleGrid );
    }
};