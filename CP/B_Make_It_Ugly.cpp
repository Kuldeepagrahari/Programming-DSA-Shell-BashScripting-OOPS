#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n ;
        vector<int> v(n);
        for(int i = 0 ;i < n ;i ++ )cin >> v[i];
        int flag = 1;
        for ( int i = 1; i< n -1 ; i ++ ){
            if ( v[i] != v[i-1] ){
                if ( v[i-1] != v[i+1<n?i+1:i] )flag = 0;
                i++;
            }
        }
        if ( flag == 0 )cout << "0\n";
        else { 
        // cout << "sam";
        int f = v[0];
        int c = 0;
        int ans = INT_MAX;
        for ( int i = 0; i < n ; i ++ ){
            if ( v[i] == f ){
               c++;
            }
            else{ 
                ans = min(c,ans);
                c = 0;
            }
        }

        ans = min (ans, c);
        if ( ans == n)cout << "-1\n";
        else 
        cout << ans << endl;
        }

        
    }
}

    //  4 4 5 6 4 6
    //  4 4 4 6 4 4
    // 6 6  6 4 6 4 6 6 5 6 6 6 6