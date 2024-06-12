#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
        
    int q;
    cin >> q;

    while ( q-- ){
        int k ,n ;
        cin >> n >> k;
        
        queue<int> q;
        int ans;
        for ( int i = 1; i <= n ; i++ )q.push(i);

        for ( int i = 0; i< k ; i++ ){
            int frnt = q.front();
            q.pop();
            if ( q.size() == 0){
                ans = frnt;
                break;
            }
            int frnt2 = q.front();
            q.pop();
            ans = frnt2;
            q.push(frnt);
        }
        cout << ans << endl;
    }
}