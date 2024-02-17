#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int k;
    cout << "Enter truck size: ";
    cin >> k;

    vector<pair<int,int>> vp;
    cout << "Enter size and values:" << endl;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vp.push_back({b, a});
    }

    sort(vp.begin(), vp.end());
    reverse (vp.begin(), vp.end());
    // sort o(nlogn)

    int ans = 0;
    int size = k;
    for ( auto &s : vp) {
        if (s.second <= size) {
            size -= s.second;
            ans += s.first * s.second;
        } else {
            ans += size * s.first;
            break;
        }
    }
    // iter o(n)
    
    cout  << ans << endl;

    return 0;
}
