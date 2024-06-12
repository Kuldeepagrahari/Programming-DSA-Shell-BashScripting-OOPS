class Solution {
public:

    int LO ( vector<int>& nums, int target ,int l, int r){
       
        int  lo = -1;

        while ( l <= r ){
            int mid =  l + ( r - l )/2;
            if ( nums[mid] == target) {
                lo = mid;
                l = mid + 1;
            }
            else if ( nums[mid] > target ){
                
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        
        return lo;
    }
    int FO ( vector<int>& nums, int target, int l, int r){
       
        int fo = -1;

        while ( l <= r ){
            int mid =  l + ( r - l )/2;
            if ( nums[mid] == target ){
                 fo = mid;
                r = mid - 1;
            }
           else if ( nums[mid] > target ){
              
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        
        return fo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int fo , lo;
        int n = nums.size();
         fo = FO(nums,target, 0,n-1 );
         lo = LO(nums,target, 0, n-1);
        // cout << fo;
        return {fo,lo};
    }
};