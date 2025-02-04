#include <bits/stdc++.h>
using namespace std;

int Sam(vector<int> &dp, int n,int k, vector<int>&c )
{ 
   if ( k < 0 ) return INT_MAX;
   if ( k == 0 )return 0;
   int t = INT_MAX;
   int cnt = 0;
   if (dp[k] != -1) return dp[k];
   for ( int i = 0 ;i < n; i++ ){
     cnt = Sam(dp, n, k - c[i], c);
     if(cnt != INT_MAX)
     t = min(t,cnt + 1);
   }
   return dp[k] = t;
  
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for( int i = 0 ; i < n ; i ++ ){
        cin >> c[i];
    }
    
    vector<int> dp(k + 1, -1);
    
  
    // vector<int> dp(n + 1, -1);
    int ans = Sam(dp, n, k, c );
    if ( ans == INT_MAX) cout << "-1\n";
    else
    cout << ans << endl;
    // for (int i = 0 ; i < k;  i++ )cout << dp[i] << " ";
}