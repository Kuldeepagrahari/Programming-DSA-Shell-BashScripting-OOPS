#include<bits/stdc++.h>
using namespace std;
// 2 - pointers -> Expand Outwards : moving opp side l&r : o(n^2), o(1)
string LongestPallindrome(string &s, int l, int r) {
    while(l >= 0 && r < s.length() && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}

int main(){
    string s;
    cin >> s;
    int n = s.length();

    int maxLength = 0;
    string ans = "";
    for(int i = 0; i < n; i++){
        string odd = LongestPallindrome(s, i, i);
        if(odd.length() > maxLength) {
            maxLength = odd.length();
            ans = odd;
        }
        string even = LongestPallindrome(s, i, i+1);
        if(even.length() > maxLength) {
            maxLength = even.length();
            ans = even;
        }
    }
    cout << ans << endl;
}