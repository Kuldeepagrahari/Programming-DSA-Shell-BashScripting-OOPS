class Solution {
public:
    void bfs(vector<vector<char>>& board, int row,
            int col) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> Q;
        Q.push({row, col});

        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
         vector<pair<int, int>>vp;
         int f = 1;
        while (!Q.empty()) {
            auto [i, j] = Q.front();
            vp.push_back({i, j});
            Q.pop();
           for (int it = 0; it < 4; it++ ){
             int nx = x[it] + i;
             int ny = y[it] + j;
             if ( board[nx][ny] == 'O' && (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1)){
                f = 0;
                break;
             }

           }
           if ( f == 0 ) break;
            for (int it = 0; it < 4; it++) {
                int nx = x[it] + i;
                int ny = y[it] + j;

                if (nx > 0 && nx < n - 1 && ny > 0 && ny < m - 1 && board[nx][ny] == 'O') {
                    Q.push({nx, ny});
                    
                }
            }
        }
        if ( f == 1){
            for ( int i = 0; i < vp.size(); i++ ){
                board[vp[i].first][vp[i].second] = 'X';
            }
        }
      
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && i < n - 1 && j > 0 && j < m - 1 &&
                    board[i][j] == 'O') {
                    bfs(board, i, j);
                }
            }
        }
      
    }
};