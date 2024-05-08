class Solution {
public:

    int solve ( string &s, string &s2, int i, int j ,       vector<vector<int>> &dp) {
        if ( i < 0  || j < 0 ){
            return 0;
        }

        if ( dp[i][j] != -1 )return dp[i][j];

        int ans = 0;

        if ( s[i] == s2[j] ){
            ans = 1 + solve ( s, s2 , i - 1 , j - 1, dp );
               return dp[i][j] = ans;
        }
         else {
           ans = 0 + max ( solve ( s , s2, i - 1, j , dp ), solve (s ,s2 ,i , j -1 , dp ));
              return dp[i][j] = ans;
        }

     
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();

        vector<vector<int>> dp (l1+1, vector<int>(l2+1, -1 ));
        return solve ( text1, text2, l1-1, l2-1 , dp );
    }
};