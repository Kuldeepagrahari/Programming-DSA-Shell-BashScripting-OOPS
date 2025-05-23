#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// Atmost K : mx - mn <= k
int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0;
    ll ans = 0;
    deque<int> MX;
    deque<int> MN; 
    
    for(int r = 0; r < n; r++){ 
        while(!MX.empty() && v[MX.back()] < v[r]){
            MX.pop_back();
        }
        MX.push_back(r);
        
        while(!MN.empty() && v[MN.back()] > v[r]){
            MN.pop_back();
        }
        MN.push_back(r);
    
        while(v[MX.front()] - v[MN.front()] > k){
            if(!MX.empty() && MX.front() == l){
                MX.pop_front();
            }
            if(!MN.empty() && MN.front() == l){
                MN.pop_front();
            }
            l++;
        }
        ll rangeOfValidL_ForFixedR = r - l + 1;
        ans += rangeOfValidL_ForFixedR;
    }
    cout << ans << endl;

}