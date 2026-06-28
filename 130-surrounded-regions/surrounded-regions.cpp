class Solution {
public:

void dfsMark(vector<vector<char>>& board, int i, int j) {
    int m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
    board[i][j] = 'A'; 
    dfsMark(board, i + 1, j);
    dfsMark(board, i - 1, j);
    dfsMark(board, i, j + 1);
    dfsMark(board, i, j - 1);
}
void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    if (m == 0) return;

    // Mark all border-connected 'O's as 'A'
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') dfsMark(board, i, 0);
        if (board[i][n - 1] == 'O') dfsMark(board, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') dfsMark(board, 0, j);
        if (board[m - 1][j] == 'O') dfsMark(board, m - 1, j);
    }

    // Flip rest 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 'A') board[i][j] = 'O';
        }
    }
}

};