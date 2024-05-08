class Solution {
public:
 int solve ( vector<int>& nums, int ind, vector<int > &dp ){
    // last k include kiya first ko nhi
        if ( ind <= 0 ) return 0; 
        if ( ind == 1 ){
            return nums[ind];
        }
        if ( dp[ind] != -1 ) return dp[ind];
        
        int a1 = solve ( nums, ind - 2 , dp ) + nums[ind];
        int a2 = solve ( nums, ind - 1, dp );
        dp[ind] = max ( a1, a2 );
        return dp[ind];
    }
 int solve3 ( vector<int>& nums, int ind, vector<int > &dp ){
    //last ko include nhi kiya first ko kiya
        if ( ind < 0 ) return 0; 
        if ( ind == 0 ){
            return nums[ind];
        }
        if ( dp[ind] != -1 ) return dp[ind];
        
        int a1 = solve3 ( nums, ind - 2 , dp ) + nums[ind];
        int a2 = solve3 ( nums, ind - 1, dp );
        dp[ind] = max ( a1, a2 );
        return dp[ind];
    }

    int rob(vector<int>& nums) {
        vector<int> dp ( nums.size(), -1 );
        vector<int> dp2 ( nums.size()-1, -1  );
        int n = nums.size();
        // return solve(nums,n-1,dp);
        if ( n == 1 )return nums[0];
        return max(solve(nums, n-1, dp), solve3(nums,n-2,dp2));
    }
};