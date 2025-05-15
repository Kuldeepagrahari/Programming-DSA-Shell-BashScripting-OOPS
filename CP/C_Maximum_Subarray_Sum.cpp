#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int mxSubarraySum = 0;
        int mxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') {
                sum += v[i];
                mxSum = max(mxSum, sum);
                if(sum < 0) sum = 0;
            } else {
                mxSubarraySum = max(mxSubarraySum, mxSum);
                sum = 0;
                mxSum = INT_MIN;
            }
        }
        mxSubarraySum = max(mxSubarraySum, mxSum);
        if(mxSubarraySum > k) cout << "NO\n";
        else if(mxSubarraySum == k) {
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                if(s[i] == '0') {
                    cout << -1000000000 << " ";
                }else cout << v[i] << " ";
            }
            cout << endl;
        }else{
            // 2 0 8 -10 0 12
        }
        
    }
   
}