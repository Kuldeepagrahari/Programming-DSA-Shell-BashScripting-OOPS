#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool predicate(ll w, ll h, ll n, ll size){
  
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<double> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int mx = *max_element(v.begin(), v.end());
    //search space: [0, max(v)]
    int l = 0, r = mx;
    
    double ans = r;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(predicate(w, h, n, mid)){
            ans = min(ans, mid);
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}