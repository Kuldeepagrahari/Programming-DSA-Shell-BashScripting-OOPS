
    string solve ( string &s, string &s2 ,  int i, int j ,  vector<vector<string>> &dp) {
        if ( i < 0  || j < 0 ){
            return "";
        }

        if ( dp[i][j] != "#" ) return dp[i][j];

        string  ans = "";

        if ( s[i] == s2[j] ){
			if ( ans == "#" )ans = "";
          
               return  dp[i][j] =  solve ( s, s2 , i - 1 , j - 1, dp ) + s[i];
        }
         else {
			 string ss1 = solve ( s , s2, i - 1, j , dp ), 
			 ss2 = solve ( s , s2, i , j - 1 , dp );
          int x1 = ss1.length();
		  int x2 = ss2.length();

		  if ( x1 > x2 ){
			  return dp[i][j] = ss1;
		  }
          else {
			  return dp[i][j] = ss2;
		  }
          
        }

     
    }


string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	   int l1 =s1.length(), l2 = s2.length();

        vector<vector<string>> dp ( l1+1, vector<string>(l2+1, "#" ));
        string ans = solve ( s1, s2, l1-1, l2-1 , dp );
        
        // cout << ans << endl;
        return ans;
}