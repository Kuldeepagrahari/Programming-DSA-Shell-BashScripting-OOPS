#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool predicate(ll w, ll h, ll n, ll size){
    ll rows = size / w;
    ll cols = size / h;
    
    return rows * cols >= n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll w, h, n;
    cin >> w >> h >> n;

    //search space : [1, max(w, h) * n]
    ll max_size = 1e18;
    ll l = 1, r = min(max(w, h) * n, max_size);
    
    ll ans = r;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(predicate(w, h, n, mid)){
            ans = min(ans, mid);
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}