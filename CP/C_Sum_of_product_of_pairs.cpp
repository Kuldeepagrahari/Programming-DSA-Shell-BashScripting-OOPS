#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    int n;
    cin>>n;
    int v[n];
    for ( int i=0;  i < n; i++){
        cin >> v[i];
    }
    int pre[n+1];
    pre[n]=0;
    for ( int i= n-1; i>=0; i-- ) {
        pre[i]= (pre[i+1] + v[i])%mod;
    }
    int ans =0;
    for ( int i=0;i< n;i++ ){
        int val= (v[i] * pre[i+1])%mod;
        ans= (ans + val)%mod;
    }
    cout << ans%mod << endl;
}