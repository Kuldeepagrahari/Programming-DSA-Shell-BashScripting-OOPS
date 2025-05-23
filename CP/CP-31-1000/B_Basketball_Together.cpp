#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());

    int ans = 0;
    
    int tot_cnt = 0;
    for(int i = 0; i < n; i++){
        int cnt = (d / v[i]) + 1;
        tot_cnt += cnt;
        if(tot_cnt > n) break;
        ans ++;
        
    }
    cout << ans << endl;
    
        

}
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
}