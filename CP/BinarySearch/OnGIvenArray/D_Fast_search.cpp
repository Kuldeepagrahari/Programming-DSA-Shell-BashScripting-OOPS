#include<bits/stdc++.h>
using namespace std;
class BinarySearch{
    private:
    vector<int> v;
    int n;
    public:
    BinarySearch(vector<int>& v){
        this -> v = v;
        n = v.size();
    }
    int search(int k){
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
    int lowLowerBound(int k){
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
    int lowerBound(int k){
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
    int upperbound(int k){
        int l = 0, r = n - 1;
        int ans = n + 1;
        while(r >= l){
            int mid = l + (r - l) / 2;
            int x = v[mid];
            if(x > k){
                ans = mid + 1;
                r = mid - 1;
            }else l = mid + 1;
        }
        return ans;
    }    
   
};
int main(){
    int n, q;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    BinarySearch *bs = new BinarySearch(v);
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int lb = bs -> lowerBound(l); //1-based return to handle edge cases correctly by itself
        int ub = bs -> upperbound(r); //1-based return ----------------------------------------
        int cnt = ub - lb;
        cout << cnt << " ";
    }
    cout << endl;
}