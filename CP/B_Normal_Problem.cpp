#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while ( t-- )
    {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());

        for(char &ch : s ){
            if(ch == 'p')ch = 'q';
            else if ( ch == 'q')ch = 'p';
        }
        cout << s << endl;


    }
}