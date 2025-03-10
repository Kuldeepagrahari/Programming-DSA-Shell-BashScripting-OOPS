/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public: 
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, int u){
        vis[u] = 1;

        for ( auto )
    }
    bool canFinish(int num, vector<vector<int>>& pr) {
        int n = pr.size();
        vector<vector<int>>adj(num);
        for ( int i = 0 ; i < n ; i ++ ){
          adj[pr[i][1]].push_back(pr[i][0]);
        }

        for ( int i = 0; i < n ; i ++ ){
            if ( !vis[i] ){

            }
        }
    }
};
// @lc code=end

