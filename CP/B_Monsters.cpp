#include <bits/stdc++.h>
using namespace std;
class cmp{
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back({x % k, i});
        }
        sort(v.begin(), v.end(), cmp);
      
        for ( int i = 0 ; i < n ; i ++ ){
            cout << v[i].second + 1<< " ";
        }
        cout << endl;
        

        
    }


}