 const int mod = 1e9+7;
    //Function to find the nth catalan number.
    
    int cnt ( int n , int oc, int cc , 
    vector<vector<int>> &dp ){
        if ( cc == oc && oc == n ){
            return 1;
        }
        int sum = 0;
         if (cc > oc) {
        return 0;
    }
        if ( dp[oc][cc] != -1 ){
            return dp[oc][cc];
        }
        if ( cc < oc ){
            sum = (sum + cnt ( n, oc, cc + 1 ,dp ))%(mod);
        }
        
        if ( oc < n ){
            sum = ( sum + cnt (n, oc + 1, cc ,dp ))%(mod);
        }
        
         return dp[oc][cc] = sum%mod;
    }
    int findCatalan(int n) 
    {
        //code here
        vector<vector<int>> dp(n+1, vector<int>(n +1,-1));
        return cnt (n, 0, 0,dp);
        
        
        
    }