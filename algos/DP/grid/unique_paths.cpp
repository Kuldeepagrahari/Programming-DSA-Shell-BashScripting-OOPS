class Solution {
public:
    
    int solve ( int ans , int row, int col , int m, int n , vector<vector<int>> &dp ){
        if (row == m-1 && col == n-1 ){
            return 1;
        }
        if ( dp[row][col] != -1 ){return dp[row][col];}
        int right = 0 , down = 0;
        if ( col + 1 < n )
        right = solve ( ans, row, col + 1 , m , n , dp ) ;
        if ( row + 1 < m )
        down = solve (ans, row + 1, col , m , n , dp );
        dp[row][col]= ( right + down );
        cout << ans ;
        return dp[row][col];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp ( m, vector<int>(n, -1 ));
        return solve ( 0 ,0 , 0 , m , n, dp );
    }
};