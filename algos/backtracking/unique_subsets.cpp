class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void solve(vector<int>& nums,int ind){
         ans.push_back(v);
         if(ind==nums.size())return;
         
          for(int i=ind;i<nums.size();i++){
              if(i>ind && nums[i]==nums[i-1])continue;
              v.push_back(nums[i]);
              solve(nums,i+1);
              v.pop_back();

          }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};