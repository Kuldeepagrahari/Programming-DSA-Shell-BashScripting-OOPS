#include<bits/stdc++.h>
using namespace std;


template <typename Container>
void samPrinter(const Container &samContainer)
{
    for (auto samIt = std::begin(samContainer); samIt != std::end(samContainer); ++samIt)
    {
        std::cout << *samIt << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void samPairPrinter(const Container &samContainer)
{
    for (auto samIt = std::begin(samContainer); samIt != std::end(samContainer); ++samIt)
    {
        std::cout << "(" << samIt->first << ", " << samIt->second << ") ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    void updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
       cout << "sam";
        vector<vector<int>> grid(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({0, 0});
        

        int xx[] = {-1, 0, 1, 0};
        int yy[] = {0, 1, 0, -1};
    cout << "sam";
        while (!q.empty()) {    cout << "sam";
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {    cout << "sam";
                int nx = cx + xx[i], ny = cy + yy[i];
                if ( nx >= 0 && nx < m && ny >= 0 && ny < n)
                if (mat[nx][ny] != 0 && grid[nx][ny] > 1 + grid[cx][cy]) {
                    grid[nx][ny] = 1 + grid[cx][cy];
                    q.push({nx, ny});
                }
            }    cout << "sam";
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
        }
        }
    };

    int main(){
        vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
        Solution sam;
        sam.updateMatrix(mat);


    }