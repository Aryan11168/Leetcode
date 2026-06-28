class Solution {
public:

void dfs(int i,int j,vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' || grid[i][j]=='#') return;
    grid[i][j]='#';
    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);
    return;
}

int numIslands(vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                cnt++;
                dfs(i,j,grid);
            }
        }
    }
    return cnt;
}
};