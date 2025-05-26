#include<bits/stdc++.h>
using namespace std;
class BinarySearch{
    public:
    int search(vector<int>& v, int k){
        int n = v.size();
        int l = 0, r = n - 1;
        while(r >= l){
            int mid = l + (r - l) / 2;
            int x = v[mid];
            if(x == k) return mid;
            else if(x < k) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    int lowLowerBound(vector<int>& v, int k){
        int n = v.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while(r >= l){
            int mid = l + (r - l) / 2;
            int x = v[mid];
            if(x <= k){
                ans = mid + 1;
                l = mid + 1;
            }else r = mid - 1;
        }
        return ans;
    }
   
};
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    while(q--){
        int k;
        cin >> k;
        BinarySearch bs;
        cout << bs.lowLowerBound(v, k) << endl;
    }
}