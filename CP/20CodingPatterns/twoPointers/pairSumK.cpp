#include<bits/stdc++.h>
using namespace std;

int main(){
    // Sorted array : O(n), o(1)
    int arr[] = { 1, 2 , 4 , 11, 15};
    int k = 10;
    
    int n = sizeof(arr) / sizeof(arr[0]);
    // two pointers -> compressed : moving opp side r&l : o(n), o(1)
    int i = 0, j = n - 1;
    pair<int, int> ans = {-1, -1};
    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum > k) j --;
        else if(sum < k) i++;
        else {
            ans = {arr[i], arr[j]};
            break;
        }
    }
    if(i == j) cout << "No such pair found\n";
    else cout << ans.first << " " << ans.second << endl;

    // unsorted array : TWO SUM : O(n), O(n) / o(nlogn) -> sort then find, o(1)
    int brr[] = { 1, 12 , 4 , 110, 15};
    k = 23;
    n = sizeof(brr)/sizeof(brr[0]);
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        int num1 = brr[i];
        int num2 = k - num1;
        if(st.count(num2)){
            ans = {num1, num2};
            break;
        }
        st.insert(num1);
    }
    if(ans == make_pair(-1, -1)) cout << "No such pair found\n";
    else cout << ans.first << " " << ans.second << endl;


}