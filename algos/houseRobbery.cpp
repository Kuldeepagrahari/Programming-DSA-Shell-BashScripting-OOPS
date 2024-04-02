class Solution {
public:
    int solve ( vector<int>& nums, int ind, vector<int > &dp ){
        if ( ind < 0 ) return 0; 
        if ( ind == 0 ){
            return nums[ind];
        }
        if ( dp[ind] != -1 ) return dp[ind];
        
        int a1 = solve ( nums, ind - 2 , dp ) + nums[ind];
        int a2 = solve ( nums, ind - 1, dp );
        dp[ind] = max ( a1, a2 );
        return dp[ind];
    }

    int tab ( vector<int>& nums ){
        int n =  nums.size();
        vector<int> dp ( n+1 , 0 );
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for ( int i = 2; i < n; i++ ){
            
            int acc = dp[i-2] + nums[i];
            int rej = dp[i-1] + 0;
            dp[i] = max ( acc, rej );
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int maxi = 0;
        vector<int> dp ( nums.size(), -1 );
        int n = nums.size();
if (n == 1) return nums[0];
// else if ( n == 2 )return max ( nums[0] , nums[1] ); /
        int ans = tab ( nums);
        return ans;

    }
};