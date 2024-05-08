class Solution {
public:
vector<string>ans;

    void solve(int n,int pos,int open_cnt,int close_cnt,string s){
        // base
        if(close_cnt==n){
            ans.push_back(s);
            return;
        }
        // add ) only when its cnt is lesser
        if(close_cnt<open_cnt){
      
            s.push_back(')');
            solve(n,pos+1,open_cnt,close_cnt+1,s);
            s.pop_back();// erase prev add whwn you are baktracking
        }
        // add ( jabtak iska cnt n ke barabar na ho jaye
        if(open_cnt<n){
            s.push_back('(');
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