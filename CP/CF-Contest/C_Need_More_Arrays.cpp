#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 1;
    int l = 0;
    for(int i = 1; i < n; i++){
       if(v[i] > v[l] + 1){
            ans++;
            l = i;
        }
       
           
    }
    cout << ans << endl;
}
int main(){
     int t;
     cin >> t;
     while(t--) solve();
}