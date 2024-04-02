#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int equalPairs(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();

        // if(arr[0][0]==11&&arr[0][1]==1&&arr[1][0]==1&&arr[1][1]==11)return 2;

        unordered_map<vector<int>, int> mp1;
        unordered_map<vector<int>, int> mp2;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                temp.push_back(arr[i][j]);
            }
            // row.push_back(temp);
            mp1[temp]++;
            // cout << temp << " ";
        }

        /// for colum
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(arr[j][i]);
                // temp+=p;
            }
            // col.push_back(temp);
            // cout << temp << " ";
            mp2[temp]++;
        }

        int ans1 = 0;

        for (auto x : mp1)
        {
            if (mp2.find(x.first) != mp2.end())
            {
                int k = x.second;
                int m = mp2[x.first];
                ans1 += (k * m);
            }
        }

        return ans1;

        // return 0;
    }
};

int main(){

}