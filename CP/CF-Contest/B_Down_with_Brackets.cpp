#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int open = 0, closed = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') open ++;
        else closed ++;
        if(open - closed == 0) cnt++;
    }
    if(cnt > 1) cout << "YES\n";
    else cout << "NO\n";


}
int main(){
     int t;
     cin >> t;
     while(t--) solve();
}