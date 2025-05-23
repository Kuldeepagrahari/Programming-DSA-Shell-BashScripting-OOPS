#include<bits/stdc++.h>
using namespace std;
//O(n+m)

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> v2(m);

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int j = 0; j < m; j++) cin >> v2[j];

    vector<int> merged(n + m);

    int i = 0, j = 0, k = 0;

    while(i < n || j < m){
        if(j == m || i < n && v[i] < v2[j]){
            merged[k++] = v[i++];
        }else{
            merged[k++] = v2[j++];
        }
    }
    for(int i = 0; i < n + m; i++) cout << merged[i] << " ";


}