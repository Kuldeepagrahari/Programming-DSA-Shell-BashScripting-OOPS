class Solution {
public:



 int minFallingPathSum(vector<vector<int>>& arr) {
        
    int n=arr.size();
    int mine=INT_MAX;
    vector<vector<int>>dp(n,vector<int>(n,1e6));

    // return solve ( 0, 0, arr, dp , n );
    for ( int i = 0 ;i < n ; i++ ){
        dp[0][i] = arr[0][i];
    }
    
    int yy[] = {-1,0,1};
    for ( int i = 0; i < n ; i ++) {
        for ( int j = 0; j  < n ; j++ ){
           for ( int k = 0; k < 3; k++ ){
            int nx = i + 1;
            int ny = j + yy[k];
            if ( nx < n &&  ny >= 0 && ny < n ){
                dp[nx][ny] = min ( dp[i][j] + arr[nx][ny], dp[nx][ny]);
            }
           }
        }
    }
  
    int ans = INT_MAX;
    for ( int i = 0; i< n ; i++ ){
        ans = min ( dp[n-1][i], ans );
    }

    return ans;
}
};