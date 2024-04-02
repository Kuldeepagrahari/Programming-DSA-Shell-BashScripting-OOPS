#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe (int row, int col ,char val,  vector<vector<char>>& board){
        // row
        for ( int i = 0; i< 9; i++ ){
            if ( i == col )continue;
            if ( board[row][i] == val )return false;
        }
        // col
         for ( int i = 0; i< 9; i++ ){
            if ( i == row )continue;
            if ( board[i][col] == val )return false;
        }
        // matrix
        for ( int i = 0; i< 9 ; i++ ){
            if ( board[3*(row/3) + i/3][3*(col/3) + i%3] == val )return false;
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){

        for ( int i = 0; i< 9 ; i++ ){
            for ( int j = 0; j< 9 ; j++){
                if ( board[i][j] == '.'){
                    for ( char k = '1'; k <= '9'; k++  ){
                        if ( isSafe(i,j,k,board)){
                        board[i][j] = k;
                        bool next = solve(board);
                        if ( next )return true;
                        else {
                            // backtrack
                            board[i][j]='.';
                        }
                    }
                }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve ( board);
    }

    void printBoard(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (i % 3 == 0 && i != 0)
                cout << "---------------------\n";
            for (int j = 0; j < 9; ++j) {
                if (j % 3 == 0 && j != 0)
                    cout << "| ";
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main () {
  vector<vector<char>> board2 = {
    {'6', '.', '.', '.', '.', '7', '2', '.', '.'},
    {'3', '2', '.', '.', '9', '.', '7', '.', '.'},
    {'7', '8', '.', '.', '.', '2', '6', '.', '.'},
    {'.', '.', '.', '6', '.', '4', '.', '.', '.'},
    {'5', '.', '.', '.', '.', '.', '.', '.', '8'},
    {'.', '.', '.', '3', '.', '8', '.', '.', '.'},
    {'.', '.', '5', '9', '.', '.', '.', '4', '7'},
    {'.', '.', '6', '.', '7', '.', '.', '9', '5'},
    {'.', '.', '7', '8', '.', '.', '.', '.', '6'}
};
 vector<vector<char>> board(9,vector<char>(9));

for ( int i = 0; i< 9; i++ ){
    for ( int j = 0; j< 9 ; j++ ){
        cin >> board[i][j];
    }
}

    Solution sudokuSolver;
    sudokuSolver.solveSudoku(board);
    sudokuSolver.printBoard(board);

    return 0;
}
