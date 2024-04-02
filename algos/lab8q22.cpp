#include<bits/stdc++.h>
using namespace std;

int maxTotalPoints(int n, const vector<int>& p, const vector<int>& f) {
    vector<int> dp(n + 1, 0);

  
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1]; 
        if (i - f[i - 1] - 1 >= 0) {// means prev one is not skipped
            dp[i] = max(dp[i], dp[i - f[i - 1] - 1] + p[i - 1]); 
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "no. of ques ";
    cin >> n;

    vector<int> p(n), f(n);
   
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

 
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    cout << "ans" << maxTotalPoints(n, p, f) << endl;

    return 0;
}
