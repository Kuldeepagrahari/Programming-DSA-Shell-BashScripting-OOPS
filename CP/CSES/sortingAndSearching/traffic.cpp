#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &x : a) cin >> x;
    set<int> st;
    st.insert(0);
    st.insert(n);
    //map se try kiya utna bhi dikkat nhi hua
    map<int, int> gaps;
    gaps[n] = 1;

    for(int i = 0; i < m ; i ++){
        int p = a[i];
        auto it = st.upper_bound(p);
        int up = *it;
        int low = *prev(it);
        gaps[up - low] --;
        if(gaps[up - low] == 0) gaps.erase(up - low);
        gaps[p - low]++;
        gaps[up - p]++;
        // auto mg = prev(gaps.end());
        cout << gaps.rbegin() -> first << " ";
        //erase(val) : delete all occ of val, hence erase(itr of loc of val is passed)
        // gaps.erase(gaps.find(up - low));
        // gaps.insert(p - low);
        // gaps.insert(up - p);
        // cout << *gaps.rbegin() << " ";
        st.insert(p);
    }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
