#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, char val, vector<vector<char>>& board) {
        // Check row
        for (int i = 0; i < 16; i++) {
            if (i == col) continue;
            if (board[row][i] == val) return false;
        }
        // Check column
        for (int i = 0; i < 16; i++) {
            if (i == row) continue;
            if (board[i][col] == val) return false;
        }
        // Check subgrid
        for (int i = 0; i < 16; i++) {
            if (board[4 * (row / 4) + i / 4][4 * (col / 4) + i % 4] == val) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) { // Numbers 1-9
                        if (isSafe(i, j, k, board)) {
                            board[i][j] = k;
                            if (solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    for (char k = 'A'; k <= 'G'; k++) { // Characters A-G
                        if (isSafe(i, j, k, board)) {
                            board[i][j] = k;
                            if (solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    void printBoard(vector<vector<char>>& board) {
        for (int i = 0; i < 16; ++i) {
            if (i % 4 == 0 && i != 0)
                cout << "--------------------------------------\n";
            for (int j = 0; j < 16; ++j) {
                if (j % 4 == 0 && j != 0)
                    cout << "| ";
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<char>> board(16, vector<char>(16));

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            cin >> board[i][j];
        }
    }
    // board[0][0]='A',board[1][0]='B';
    // cin >> board[2][0];
    Solution sudokuSolver;
    sudokuSolver.solveSudoku(board);
    sudokuSolver.printBoard(board);

    return 0;
}
