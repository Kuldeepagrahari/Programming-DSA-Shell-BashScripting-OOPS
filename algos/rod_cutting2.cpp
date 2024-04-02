
class Solution {
public:
int c;
 int solve ( vector<int>& coins, int amount, vector<int> &price, vector<int>&dp ){
             if ( amount == 0 ) return 0;
             if ( amount < 0 ) return -1;
             if ( dp[amount] != -1 ) return  dp[amount];
             int maxiProfit = 0;
            for ( int i = 0; i < coins.size(); i++ ){
             
               int prevProfit = solve ( coins, amount-coins[i] , price, dp);
                
               if ( prevProfit != -1 ) maxiProfit = max ( maxiProfit , prevProfit + price[i] );
            }

            dp[amount] = maxiProfit;
            return maxiProfit;
            
    }
   
     int solve2 ( vector<int>& coins, int amount ,vector<int> &price){
         vector < int > dp ( amount + 1 , -1 );
            dp[0] = 0;
            int n = coins.size();
            for ( int i = 1 ;i <= amount ; i++ ){
                 for ( int j = 0; j < n ;j ++ ){
                     if ( i-coins[j] >= 0 && dp[i-coins[j]] != -1 )
                     dp[i] = max ( dp[i], price[j] + dp[i - coins[j]] );  
                 }
            }
            if ( dp[amount] < 0 ) return  0;
            return dp[amount];

     }

    int coinChange(vector<int>& coins, int amount, vector<int> &price ) {
        vector<int> dp(amount+1,-1);
        int ans = solve ( coins,amount,price,dp );
        return ans;

    }
};
int cutSegments(int n,vector<int> &price) {
	
	Solution obj;
	vector<int> coins(n);
	for ( int i = 0; i< n; i++ ){
		coins[i] = i+1;
	}
	int ans = obj.coinChange( coins,n,price);

	return ans;
     
}

int cutRod(vector<int> &price, int n)
{    return cutSegments(n, price);
	
}
