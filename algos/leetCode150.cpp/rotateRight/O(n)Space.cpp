class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =  nums.size();
        k = k%n; // kyuki n bar rotate krnw par same array milegi, to effectivily ans hame k%n time rotate krne par hi mil jaega,  ye jaruri hai kyuki vector out of bound ho jaega
        vector<int> last_elems;
        for ( int i = n - k; i < n; i++ ){
              last_elems.push_back(nums[i]);
        }

        
        for ( int i = n-k-1  ;i >= 0; i-- ){
            nums[i + k] = nums[i];
        }

        for ( int i = 0; i <  k; i++ ) nums[i] = last_elems[i];
    }
};