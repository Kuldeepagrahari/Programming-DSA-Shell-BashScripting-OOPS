

class comp {
    vector<int>& nums; // Reference to the nums vector
    
public:
    comp(vector<int>& nums) : nums(nums) {} // Constructor to initialize the nums vector reference
    
    bool operator()(int a, int b) {
        return nums[a] > nums[b]; // Compare elements based on increasing order of values
    }
};

class Solution {
public:
    
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        vector< bool > marked(n,false);
        
        long long total = 0;
        
        for ( int i = 0; i< n; i++ ){
            marked[i] = false;
            total += nums[i];
            
        }
        priority_queue < int , vector<int> , comp > pq (nums) ; 
        
        for ( int i = 0; i <  n ;i ++ ){
            pq.push(i);
        }
        
        int m = queries.size();
        
        vector< long long > ans;
         
        for ( int i = 0; i < m; i++ ){
            int ind = queries[i][0];
            int freq = queries[i][1];
            
            if ( !marked[ ind ] ){
                total -= nums[ ind ];
                marked[ind] = true;
            }
            
            while ( freq != 0 ){
                int topind = pq.top();
                pq.pop();
                if ( !marked[topind] ){
                    total -= nums[topind];
                    marked[topind] = true;
                    freq--;
                }
            }
            
            ans.push_back(total);
            
        }
        return ans;
       
        
    }
};