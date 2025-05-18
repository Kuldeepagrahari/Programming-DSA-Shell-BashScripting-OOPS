#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> factors;
    factors.push_back(1);
    for(int i = 1; i * i <= n; i ++){
        if(n % i == 0){
            factors.push_back(i);
            if(i != 1)
            factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end());
    pair<int, int> ans = {-1, -1};
    
    int minLCM = INT_MAX;
    for(int i = 0; i < factors.size(); i ++){
        int a = factors[i];
        int b = n - factors[i];
        int gcdd = __gcd(a, b);
        long long lcm = (a * 1ll * b) / gcdd;
        if(lcm < minLCM){
            minLCM = lcm;
            ans = {a, b};
        }

    }
    cout << ans.first << " " << ans.second << endl;
        

}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}