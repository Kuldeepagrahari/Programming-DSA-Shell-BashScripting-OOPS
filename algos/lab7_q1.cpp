 #include<bits/stdc++.h>
 using namespace std;
 
 int maxMeetings(int start[], int end[], int n)
    {
       
        vector<pair<int,int>>vp;
        for ( int  i = 0; i < n ; i++ ){
            vp.push_back({ end[i], start[i] });
        }
        
        sort( vp.begin(), vp.end());
        int ans = 1;
        int j = 0;
        for ( int i = 1; i < n ; i ++ ){
            if ( vp[j].first < vp[i].second ){
                ans ++;
                j = i;
            }
                
        }
        return ans ;
    }
    int main(){
        int n;
        cin >> n;
        int start[n];
        int end[n]; 
        for ( int  i= 0; i< n; i++ ){
            cin >> start[i];
        }
        for ( int  i= 0; i< n; i++ ){
            cin >> end[i];
        }
        clock_t starter, ender;
 

        starter = clock();
        int ans =  maxMeetings(start,end,6);
        ender = clock();
 

        double time_taken = double(ender - starter) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
         cout << " sec " << endl;
        
        // O(n*logn)
    }