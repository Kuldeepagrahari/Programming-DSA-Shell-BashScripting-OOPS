class Solution {
public:
vector<string>ans;

    void solve(int n,int pos,int open_cnt,int close_cnt,string s){
        
        if(close_cnt==n){
            ans.push_back(s);
            return;
        }

        if(close_cnt<open_cnt){
      
            s+=')';
            solve(n,pos+1,open_cnt,close_cnt+1,s);
            s.pop_back();
        }
        if(open_cnt<n){
           
            s+='(';

            solve(n,pos+1,open_cnt+1,close_cnt,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
           string s;
           solve(n,0,0,0,s);
          return ans;
    }
};