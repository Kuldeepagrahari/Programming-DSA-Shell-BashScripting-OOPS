
class Solution {
public:
    int solve(string &s, string &t, int sIndex, int tIndex, vector<vector<int>> &dp) {

        
        // If all characters of t are matched, return 1
        if (tIndex == t.length()) {
            return 1;
        }

        // If we have exhausted all characters in s
        if (sIndex == s.length()) {
            return 0;
        }

        // If the result is already calculated, return it
        if (dp[sIndex][tIndex] != -1) {
            return dp[sIndex][tIndex];
        }

        int take = 0, notTake = 0;

        // If current characters match, we can either take or not take this character
        if (s[sIndex] == t[tIndex]) {
            take = solve(s, t, sIndex + 1, tIndex + 1, dp);
        }

        // Move to the next character in s
        notTake = solve(s, t, sIndex + 1, tIndex, dp);

        // Update dp with the result and return the total count
        return dp[sIndex][tIndex] = take + notTake;
    }

    int numDistinct(string s, string t) {
        if (s.length() < t.length()) {
            return 0;
        }

        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, 0, 0, dp);
    }
};