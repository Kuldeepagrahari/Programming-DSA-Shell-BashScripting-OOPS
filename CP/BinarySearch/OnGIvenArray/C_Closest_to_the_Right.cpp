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
        int ans = 0; // if no inbw element satisfies
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
    // inbuilt STL lowerbound or closest to right
    int lowerBound(vector<int>& v, int k){
        int n = v.size();
        int l = 0, r = n - 1;
        int ans = n + 1; // if no inbetween element satisfies
        while(r >= l){
            int mid = l + (r - l) / 2;
            int x = v[mid];
            if(x >= k){
                ans = mid + 1;
                r = mid - 1;
            }
            else l = mid + 1;
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
        cout << bs.lowerBound(v, k) << endl;
    }
}