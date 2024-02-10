#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
    int n, k; cin >> n >> k;
    pair<int,int> a[n + 1];

    for( int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }

    for( int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }

    sort(a + 1, a + n + 1);


    int ans1 = k;
    int cnt = 1;
    //hame pehle se sirf ek ko dene ki jarurat h
    // fir jo log p ya usse kam me transsfer krenge unke sahare transfer krwayenge fir 
    // jo jada me kr rahe h untak vapas pak se krwayenge

    for(int i = 1; i <= n; i++) {
        // this case was missing jab values p ya k se badi 
        //hone lag jaygi to hum p ya k lenge matlab direct
        // pak se info dilwayenge
        // if(a[i].first>k){
        //     int baki = n - cnt;
        //     ans1 += k * baki;
        //     break;
        // }
      
         if(a[i].second+cnt>n || a[i].first>k) {
            int baki = n - cnt;
            ans1 += min(k,a[i].first) * baki;
            break;
        }
          else {
            cnt += a[i].second;
            ans1 += a[i].first * a[i].second;

        }
    }

    cout << min(ans1, n * k) << '\n';
    }
}