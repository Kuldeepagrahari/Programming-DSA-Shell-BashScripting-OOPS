#include <bits/stdc++.h> 
int ans=0;
int rec( vector<int>&heights , int n , int ind , vector<int>&dp){
       if ( ind <= 0 ){
           return 0;
       }
       int oneStep = INT_MAX,twoStep = INT_MAX;
        
       if ( dp[ind] != -1 )return dp[ind];
       if (ind - 1 >= 0) {
            oneStep = rec(heights, n, ind - 1 ,dp) + abs(heights[ind] - heights[ind - 1]);
        
       }
       if (ind - 2 >= 0) {
            twoStep = rec(heights, n, ind - 2 ,dp) + abs(heights[ind] - heights[ind - 2]);
           
       }
    //    cout << oneStep << " " << twoStep << " " << ans << endl;
       ans = min ( oneStep, twoStep );
       return dp[ind] = ans;
     
}
int frogJump(int n, vector<int> &heights)
{    
      vector<int> dp ( n+1,  -1 );
      return rec( heights, n , n-1 ,dp);
}

// min cost to go from stair 1 to n, frog can jump either 1 or 2 step only
// O(n)