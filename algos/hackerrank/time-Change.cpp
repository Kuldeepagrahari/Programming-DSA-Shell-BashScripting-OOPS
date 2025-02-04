#include<bits/stdc++.h>
using namespace std;

int Sam ( vector<vector<int>> &dp, int ind1, int ind2, string a, string b, string c, string cc ){
   
   
}
int main(){
       
   int t;
   cin >> t;
   while  ( t-- ){
    string a, b, c;

    cin >> a >> b >> c;
    int la = a.length(), lb = b.length(), lc = c.length();
    vector<vector<int>> dp(la + 1, vector<int>(lb + 1, -1 ));
    cout << Sam(dp, 0, 0, a, b, c, "") << endl;

   }
}