#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
    string n,m,k,s,ss;
        cin >> s >> ss;
        n = s;
        m = ss;
 
        int ls = s.length();
        int lss = ss.length();
        if ( n < m ){
            int ind = ls-1;
        for ( int i = 0; i< ls; i++ ){
            if ( s[i] < ss[i] ){
                swap(s[i],ss[i]);
                ind = i;break;
            }
        }

        for ( int i = ind + 1; i< ls;i++ ){
            if ( s[i] > ss[i] )swap(s[i],ss[i]);
        }
        }
        else {
            int ind = ls-1;
        for ( int i = 0; i< ls; i++ ){
            if ( s[i] > ss[i] ){
                swap(s[i],ss[i]);
                ind = i;break;
            }
        }

        for ( int i = ind + 1; i< ls;i++ ){
            if ( s[i] < ss[i] )swap(s[i],ss[i]);
        }
        }

        cout << s << endl << ss << endl;

        
    }
}
