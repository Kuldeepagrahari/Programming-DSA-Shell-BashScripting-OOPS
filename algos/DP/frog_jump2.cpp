

int rec( vector<int>&heights , int n , int ind , vector<int>&dp, int k ){
       if ( ind <= 0 ){
           return 0;
       }
       int Step = INT_MAX;
        
       if ( dp[ind] != -1 )return dp[ind];

       int ans = INT_MAX;
       
       for ( int i = 1; i<= k ; i++ ) {
           if (ind - i >= 0) {
             Step = rec(heights, n, ind - i, dp, k ) +
                    abs(heights[ind] - heights[ind - i]);
           }
           ans = min ( ans , Step  );
       }
   
    //    ans = min ( oneStep, twoStep );
       return dp[ind] = ans;
     
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
          vector<int> dp ( n+1,  -1 );
          return rec ( height, n, n-1, dp, k );
}

// frog can jump upto k: 1,2,3 ,,,, k;
// O(n*k)