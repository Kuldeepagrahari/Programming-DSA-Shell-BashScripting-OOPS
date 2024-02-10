class Solution {
public:
    void solve(int ind ,vector<int>& candidates, int target,vector<int>&v, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target)break;
            v.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],v,ans);
            v.pop_back();
          
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {       
        // unordered_map<vector<int>,int>St;
           vector<int>v;
           vector<vector<int>>ans;

        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,v,ans);
        return ans;
    }
};