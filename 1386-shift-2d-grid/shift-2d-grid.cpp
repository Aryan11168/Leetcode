class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        int modu=m*n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int nxt=((n*i)+j+k)%modu;
                int ni=nxt/n;
                int nj=nxt%n;
                ans[ni][nj]=grid[i][j];
            }
        }
        return ans;
    }
};