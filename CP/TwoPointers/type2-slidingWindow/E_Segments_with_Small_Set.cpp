#include<bits/stdc++.h>
using namespace std;
// Atmost K : Unique Elements
int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    long long sum = 0;
    int l = 0;
    long long ans = 0;
    unordered_map<int, int> mp; 

    for(int r = 0; r < n; r++){
        mp[v[r]]++;
        while(mp.size() > k){
            mp[v[l]]--;
            if(mp[v[l]] == 0) mp.erase(v[l]);
            l++;
        }
        int rangeOfValidL_ForFixedR = r - l + 1;
        ans += rangeOfValidL_ForFixedR;
    }
    cout << ans << endl;

}