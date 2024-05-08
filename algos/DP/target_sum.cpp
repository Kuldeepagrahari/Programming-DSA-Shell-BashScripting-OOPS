class Solution {
public:
    int solve ( vector<int>& nums, int tar, vector< vector<int> > &dp, int ind, int n ){
      if ( ind == n-1 ){
        if ( tar == 0 && nums[ind] == 0 ) return 2;
        else if ( tar == 0 || nums[ind] == tar ) return 1;
        return 0;
      }

      if ( dp[tar][ind] != -1 )return dp[tar][ind];

    int take = 0;
    if ( tar >= nums[ind] )
     take = solve ( nums, tar-nums[ind] , dp, ind + 1, n );
     int notTake = solve ( nums, tar, dp, ind + 1 , n );
     return dp[tar][ind] = (take + notTake );

      
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for ( int i = 0; i < n ; i++ ){
            sum += nums[i];
        }
        if ( (sum-target) & 1 || sum < target) return 0;
         int tar = (sum-target)/2;
         
        vector< vector<int> > dp ( tar + 1 , vector<int>(n, -1 ) );
        return solve ( nums, tar , dp, 0 , n );
    }
};