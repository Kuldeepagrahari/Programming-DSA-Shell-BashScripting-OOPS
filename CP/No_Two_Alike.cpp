#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
      int n, x, k;
      cin >> n;
      vector<int> v(n);

      for(int i = 0 ; i < n ; i ++ ) cin >> v[i];

      map<int,int>mp;
  
      for ( int i = 0 ; i < n; i ++ ){
        mp[v[i]]=i;
      }
    // for(auto it: mp){
    //     cout << it.first << " " << it.second << endl;
    // }
        set<int> S;
      int st=0;
      int en=mp[v[st]];
      int ans=0;

      while(true){
        while(st<en ){
            en=max(en,mp[v[st]]);
            S.insert(v[st]);
            st++;
        }
        if(st==n) break;
        st++;
        en=mp[v[st]];
        ans+=S.size();
        S.clear();
        // if(st==n-1) break;
      }
        cout<<ans<<endl;
     
     
        

    }
}