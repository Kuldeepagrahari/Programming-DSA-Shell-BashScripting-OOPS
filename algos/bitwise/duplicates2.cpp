class Solution {
public:
    vector<int> repeatedElements(int arr[], int n) {
        int xor_all = 0;
        int x_xor_y = 0;
        
        // Find XOR of all elements from 1 to n and all elements in the array
        for (int i = 1; i <= n; i++) {
            xor_all ^= i;
            x_xor_y ^= arr[i - 1];
        }
        for (int i = 0; i < n + 2; i++) {
            x_xor_y ^= arr[i];
        }
        
        // Find the rightmost set bit in x_xor_y
        int rightmost_set_bit = x_xor_y & ~(x_xor_y - 1);
        
        // Divide all numbers from 1 to n into two groups based on the rightmost set bit
        int group1 = 0, group2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i & rightmost_set_bit) {
                group1 ^= i;
            } else {
                group2 ^= i;
            }
        }
        
        // Divide the array into two groups based on the rightmost set bit
        for (int i = 0; i < n + 2; i++) {
            if (arr[i] & rightmost_set_bit) {
                group1 ^= arr[i];
            } else {
                group2 ^= arr[i];
            }
        }
        
        // Find the two repeating elements
        vector<int> result;
        for (int i = 0; i < n + 2; i++) {
            if (arr[i] == group1 || arr[i] == group2) {
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};
