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
    int i = 0, j = 0;
    long long eqPairCnt = 0;
    long long c1 = 0, c2 = 0;
    while(i < n || j < m){
        if(i < n && j < m && v1[i] == v2[j]){
            c1 = 1, c2 = 1;
            while(i < n - 1 && v1[i] == v1[i + 1]){
                c1++;
                i++;
            }
            while(j < m - 1 && v2[j] == v2[j + 1]){
                c2++;
                j++;
            }
            i++;
            j++;
            eqPairCnt += c1 * c2;
            c1 = 0, c2 = 0;
        }else{
            if(i < n && v1[i] < v2[j]){
                i++;
            }else j++;
        }
    }
    eqPairCnt += c1 * c2;
    cout << eqPairCnt << endl;
}