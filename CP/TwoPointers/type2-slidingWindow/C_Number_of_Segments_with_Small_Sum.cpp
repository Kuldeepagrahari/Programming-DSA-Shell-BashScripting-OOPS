#include<bits/stdc++.h>
using namespace std;
// Atmost K : Counting
int main(){
    long long n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    long long sum = 0;
    int l = 0;
    long long ans = 0;
    for(int r = 0; r < n; r++){
        sum += v[r];
        while(sum > k){
            sum -= v[l];
            l++;
        }
        int rangeOfValidL_ForFixedR = r - l + 1;
        ans += rangeOfValidL_ForFixedR;
    }
    cout << ans << endl;

}