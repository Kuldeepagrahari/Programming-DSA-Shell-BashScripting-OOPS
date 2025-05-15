#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//O(Sum of values * N) = O(10^7)
//memo ensure each (ind, value) is calculated only once as we are using same dp array for all vales, recursion calls will be made only when a unique(ind, value) is called otherwise it will return the value from dp array
int N, W;
vector<pair<int, int>> vp;
vector<vector<int>> dp;

int K(int ind, int value) {
   if(ind == N){
    if(value == 0) return 0;
    return INT_MAX;
   }

   if(dp[ind][value] != -1) return dp[ind][value];
   int t = INF;
   if(value - vp[ind].second >= 0) t = vp[ind].first + K(ind + 1, value - vp[ind].second);
   int nt = K(ind + 1, value);
   return dp[ind][value] = min(t, nt);
}

signed main(){
    cin >> N >> W;
    vp.resize(N);
    int total_value = 0;
    for(int i = 0; i < N; i++){
        cin >> vp[i].first >> vp[i].second;
        total_value += vp[i].second;
    }
    
    dp.assign(N+1, vector<int>(total_value+1, -1));

    int ans = 0;
    // Try all values from high to low
    for(int i = total_value; i >= 0; i--){
        int w = K(0, i);
        if(w <= W){
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;
}
