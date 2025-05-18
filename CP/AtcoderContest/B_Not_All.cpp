#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    int opn = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(mp.size() < m) {
            break;
        }
        opn++;
        mp[a[i]]--;
        if(mp[a[i]] == 0) {
            mp.erase(a[i]);
        }
    }
    cout << opn << endl;

}