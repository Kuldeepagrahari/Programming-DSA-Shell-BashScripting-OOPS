#include<bits/stdc++.h>
using namespace std;
 int minAnagramLength(string s) {
        // abbc abcb babc abbc
        int cnt[26] = {0};
        int ans = 0;
        for ( int i = 0; i< s.length(); i++ ){
           if ( cnt[s[i]-97] == 0 ){
            ans = i+1;
            cnt[s[i]-97]++;
           }
        }

        return ans;
    }
int main(){
string s = "abbcabcbbabcabbcd";
cout << 
minAnagramLength(s);
}