    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        
        deque<int> mx;
        deque<int> mn;
        int st = 0, end = 0;
        mx.push_back(0);
        mn.push_back(0);
        int bgst = 0;
        pair<int, int> rng;
        
        for(int i = 1; i < n; i++){
            
            int cur_win_mx = mx.front();
            int cur_win_mn = mn.front();
            
            if (abs(arr[i] - arr[cur_win_mx]) > x){
                mx.pop_front();
                st = cur_win_mx + 1;
            }
            
            if (abs(arr[i] - arr[cur_win_mn]) > x){
                mn.pop_front();
                st = cur_win_mn + 1;
            }
            
            while(!mn.empty() && arr[mn.back()] >= arr[i]) mn.pop_back();
            while(!mx.empty() && arr[mx.back()] <= arr[i]) mx.pop_back();
            
            mx.push_back(i);
            mn.push_back(i);
            if(bgst < i - st){
                rng = {st, i};
                bgst = i -st;
            }
        }
        st = rng.first;
        end = rng.second;
        vector<int> ans;
        for(int i = st; i <= end; i++)ans.push_back(arr[i]);
        return ans;
    }