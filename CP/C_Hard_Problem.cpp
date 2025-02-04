#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        int a, b, c;
        cin >> n >> a >> b >> c;
        int ans = 0;
        int n2 = n;
        ans += min(n, a);
        n-=min(n, a);
        ans += min(n2, b);
        n2-=min(n2, b);
        ans+= min(c, n2+n);
        cout << ans << endl;

    }
}