#include<bits/stdc++.h>
using namespace std;

void matrixSquare(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                ans[i][j] += mat[i][k] * mat[k][j];
            }
        }
    }
    mat = ans;
    // [1 1] [1 1]
    // [1 0] [1 0]
}

int main() {
    vector<vector<int>> mat = {{1, 1}, {1, 0}};
    matrixSquare(mat);
    int n = 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << mat[i][j] << " ";
        cout << endl;
    }

}