#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int l,r;
    cin >> l >> r;
    cout << "YES\n";
    for(int i=l; i<=r; i+=2){
        cout<<i<<" "<<i+1<<endl;
    }
}