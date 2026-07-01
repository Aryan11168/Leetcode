class Solution {
public:
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n <= 0) return -1;
    if (grid[0][0] || grid[n - 1][n - 1]) return -1;

    queue<tuple<int, int, int>> q;
    vector<vector<int>> dirs = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    q.push({0, 0, 1});
    grid[0][0] = 1;

    while (!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();
        if (r == n - 1 && c == n - 1)
            return d;

        for (auto& it : dirs) {
            int a = r + it[0];
            int b = c + it[1];
            if (a < 0 || b < 0 || a >= n || b >= n || grid[a][b])
                continue;

            grid[a][b] = 1; 
            q.push({a, b, d + 1});
        }
    }

    return -1; 
}
};