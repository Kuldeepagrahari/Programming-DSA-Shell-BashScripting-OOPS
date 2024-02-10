class Solution {
public:

    void solve(int k,int n,int ind,vector<int>&v, vector<int>elem, vector<vector<int>>&ans){

        if(n==0){
            if(elem.size()==k){ans.push_back(elem);}
             return;
        }
           for(int i=ind;i<v.size();i++){
               if(v[i]>n)continue;
               //take
               elem.push_back(v[i]);
               solve(k,n-v[i],i+1,v,elem,ans);
               //not take
               //backtrack
               elem.pop_back();
           }
      
         
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v={9,8,7,6,5,4,3,2,1};
        vector<vector<int>>ans;
        vector<int>elem;
        solve(k,n,0,v,elem,ans);
        return ans;
       
    }
};