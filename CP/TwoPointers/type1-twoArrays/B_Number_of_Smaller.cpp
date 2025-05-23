#include<bits/stdc++.h>
using namespace std;
// O(n + m)
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);

    for(int i = 0; i < n; i++) cin >> v1[i];
    for(int j = 0; j < m; j++) cin >> v2[j];
    int i = 0;
    vector<int> ans(m);
    int cnt = 0;
    for(int j = 0; j < m; j++){
        while(i < n && v1[i] < v2[j]){
            i++;
            cnt++;
        }
        ans[j] = cnt;
    }
    for(int c: ans) cout << c << " ";
    cout << endl;
}