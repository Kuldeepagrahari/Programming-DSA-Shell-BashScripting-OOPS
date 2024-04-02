 #include<bits/stdc++.h>
 using namespace std;
 
 int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
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
        int n = 6;
        // cin >> n;
        int start[] = {1,3,0,5,8,5};
        int end[] =  {2,4,6,7,9,9};
        cout << maxMeetings(start,end,6);
    }