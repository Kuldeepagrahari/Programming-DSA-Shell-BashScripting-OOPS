class Solution {
public:
     vector<vector<int>>ans;
     vector<int>v;
    void solve (vector<int>& nums,int i,int n){
        if(i==n){
           ans.push_back(v);

           return;
        }
        // take
        v.push_back(nums[i]);
        solve(nums,i+1,n);

        //not take
        v.pop_back();
        solve(nums,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        solve(nums,0,n);
        return ans;
    }
};