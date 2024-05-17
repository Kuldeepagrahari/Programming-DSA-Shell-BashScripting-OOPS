#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while ( t--){
        string x,y,a,b,m,n;

        cin >> x ;
        int l = x.length();
        if ( l == 1 ) cout << "NO\n";
        set<char> st;
        for ( int i = 0 ;i < l ;i ++ ){
             st.insert(x[i]);
        }
        if ( st.size() == 1 )cout << "NO\n";

        else {
            cout << "YES\n";
            string s = x;
            for ( int i = 0 ; i< l ; i++ ){
                if ( s[i] != s[i+1] ){swap(s[i], s[i+1] );break;}
            }
            cout << s << endl;
            
            }
       
    }
}