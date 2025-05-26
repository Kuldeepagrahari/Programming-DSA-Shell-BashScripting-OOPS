#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n; 
    vector<int> v(n);
    for(int i = 0; i < n ; i++) cin >> v[i];
    sort(v.begin(), v.end());
    // 1 1 3 4 6 6  6 8
    // 2 4 5 6 7 9 11
    int sum = v[n - 1] + v[0];
    if(sum & 1) {
        int i = 1;
        while((v[0] ^ v[i] ) % 2 == 0){
            i++;
        }
        int j = n - 2;
        while((v[n - 1] ^ v[j]) % 2 == 0){
            j--;
        }
        // cout << i << " " << j;
        int lcost = i;
        int rcost = n - j - 1;
        cout << min(lcost, rcost) << "\n";
    }else cout << "0\n";
}
int main(){
     int t;
     cin >> t;
     while(t--) solve();
}