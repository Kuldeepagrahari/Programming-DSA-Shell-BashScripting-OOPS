#include<bits/stdc++.h>
using namespace std;
#define int long long
//N = 100, W = 10^5, vi = 10^9
//O(NW)
int K(vector<pair<int, int>> &vp, vector<vector<int>> &dp, int ind, int W){
  if(ind == vp.size()) return 0;
  
  if(dp[ind][W] != -1) return dp[ind][W];
  int t = 0, nt = 0;
  if(W - vp[ind].first >= 0) t = vp[ind].second + K(vp, dp, ind + 1, W - vp[ind].first);
  nt = K(vp, dp, ind + 1, W);
  // if you traverse upto ind index and holded w' weight then the max values you gained = dp[ind][w']
  return dp[ind][W] = max(t, nt);
}
signed main(){
  int N, W;
  cin >> N >> W;
  
  vector<pair<int, int>> vp(N);
  for(int i = 0; i < N; i++){
    cin >> vp[i].first >> vp[i].second;
  }
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
  
  int mx_tot_val = K(vp, dp, 0, W);
  cout << mx_tot_val << endl;
  
}