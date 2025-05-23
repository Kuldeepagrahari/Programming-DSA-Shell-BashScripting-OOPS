#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> matrixMultiplication(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    int n = mat1.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return ans;
    // [1 1] [1 1]
    // [1 0] [1 0]
}
vector<vector<int>> matrixExponentiation(vector<vector<int>>& mat, int n) {
    if(n == 0) return {{1, 0}, {0, 1}};
    vector<vector<int>> power = matrixExponentiation(mat, n / 2);
    vector<vector<int>> mult = matrixMultiplication(power, power);
    if(n & 1) {
        return matrixMultiplication(mult, mat);
    }
    return mult;
}
int main() {
    vector<vector<int>> mat = {{1, 1}, {1, 0}};
    int n;
    cin >> n;
    vector<vector<int>> expo = matrixExponentiation(mat, n - 1);
 
    // for(int i = 0; i < 2; i++) {
    //     for (int j = 0; j < 2; j++) cout << expo[i][j] << " ";
    //     cout << endl;
    // }
    cout << n << "th element in fib seq is: " << expo[0][0] << endl;
}