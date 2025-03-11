#include<bits/stdc++.h>
using namespace std;
int K(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
  // base case : if one string gets empty, i.e i == -1 || j == -1
    if(i == s1.length()) return j + 1;
    if(j == s2.length()) return i + 1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = 0 + K(s1, s2, i + 1, j + 1, dp);
    else return dp[i][j] = 1 + min ({
       K(s1, s2, i, j + 1, dp), //insert
       K(s1, s2, i + 1, j, dp), //delete
       K(s1, s2, i + 1, j + 1, dp) //replace
    });
}

 int editDistance(string &s1, string &s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return K(s1, s2, 0, 0, dp); 
}

int main(){

    // cout << editDistance("horse", "ros") << endl;
}