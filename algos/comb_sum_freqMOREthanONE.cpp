class Solution {
public:
    // map<vector<int>,int>mp;
    vector<vector<int>>ans;
      vector<int>v;
      int sum=0;
   
    void solve2(vector<int>&candidates, int target, int ind){
        if(sum==target){
            ans.push_back(v);
            return ;
        }
        if(sum>target){
            return;
        }
        if(ind==candidates.size())return;
        v.push_back(candidates[ind]);
        sum+=candidates[ind];
        solve2(candidates,target,ind);
        v.pop_back();
        sum-=candidates[ind];
        solve2(candidates,target,ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve2(candidates,target,0);
        return ans;
    }
};