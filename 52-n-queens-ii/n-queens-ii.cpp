class Solution {
public:
    bool valid(int i,int j,int n,vector<vector<int>>& grid){
        for(int ind=0;ind<n;ind++){
            if(grid[ind][j] || grid[i][ind]) return false;
        }
        int x=i,y=j;
        while(x<n && y<n){
            if(grid[x][y]) return false;
            x++;
            y++;
        }
        x=i;y=j;
        while(x>=0 && y>=0){
            if(grid[x][y]) return false;
            x--;
            y--;
        }
        x=i;y=j;
        while(x>=0 && y<n){
            if(grid[x][y]) return false;
            x--;
            y++;
        }
        x=i;y=j;
        while(x<n && y>=0){
            if(grid[x][y]) return false;
            x++;
            y--;
        }
        return true;
    }
    int count(int row,int n,vector<vector<int>>& grid){
        if(row==n) return 1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(valid(row,i,n,grid)){
                grid[row][i]=1;
                cnt+=count(row+1,n,grid);
                grid[row][i]=0;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        return count(0,n,grid);
    }
};