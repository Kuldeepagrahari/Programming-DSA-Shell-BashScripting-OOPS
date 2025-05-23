#include<bits/stdc++.h>
using namespace std;
// AtLeast K
int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    long long sum = 0;
    int l = 0;
    int ans = 1e5+2;
    for(int r = 0; r < n; r++){
        sum += v[r];
        while(sum - v[l] >= k){
            sum -= v[l];
            l++;
        }
        int window = r - l + 1;
        if(sum >= k) 
            ans = min(ans, window);
    }
    if(ans == 1e5+2) cout << "-1\n";
    else cout << ans << endl;

}