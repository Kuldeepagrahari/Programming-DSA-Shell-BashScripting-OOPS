class Solution {
public:
int c;
    int solve ( vector<int>& coins, int amount, vector<int>&dp ){
             if ( amount == 0 ) return 0;
             if ( amount < 0 ) return INT_MAX;
             if ( dp[amount] != -1 ) return  dp[amount];
             int mini =INT_MAX;
            for ( int i = 0; i < coins.size(); i++ ){
             
                c = solve ( coins, amount-coins[i] ,dp);
                
               if ( c != INT_MAX ) mini = min ( mini , c + 1 );
            }

            dp[amount] = mini;
            return mini;
            
    }

     int solve2 ( vector<int>& coins, int amount ){
         vector < int > dp ( amount + 1 , INT_MAX);
            dp[0] = 0;
            int n = coins.size();
            for ( int i = 1 ;i <= amount ; i++ ){
                 for ( int j = 0; j < n ;j ++ ){
                     if ( i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX )
                     dp[i] = min ( dp[i], 1 + dp[i - coins[j]] );  
                 }
            }
            if ( dp[amount] < 0 ) return  INT_MAX;
            return dp[amount];

     }

    int coinChange(vector<int>& coins, int amount) {
        int mini = INT_MAX;
        // vector < int > dp ( amount + 1 ,-1);
        int ans = solve2 ( coins,amount );
        if ( ans != INT_MAX ) return ans;
        return -1;
        // o( amount * no.ofcoins )
        // space o(amount)
        // further space optimization is not possible

    }
};