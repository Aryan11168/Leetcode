class Solution {
public:
void dfsMark(vector<vector<int>>& board, int i, int j) {
    int m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 1) return;
    board[i][j] = -1; 
    dfsMark(board, i + 1, j);
    dfsMark(board, i - 1, j);
    dfsMark(board, i, j + 1);
    dfsMark(board, i, j - 1);
}
int numEnclaves(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    if (m == 0) return 0;

    // Mark all border-connected 1s as -1
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 1) dfsMark(board, i, 0);
        if (board[i][n - 1] == 1) dfsMark(board, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 1) dfsMark(board, 0, j);
        if (board[m - 1][j] == 1) dfsMark(board, m - 1, j);
    }

    // count rest
    int cnt=0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j]==1) cnt++;
        }
    }
    return cnt;
}
};