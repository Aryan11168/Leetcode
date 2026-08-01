class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> grid=board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(auto it:dirs){
                    int x=i+it[0];
                    int y=j+it[1];
                    if(min(x,y)>=0 && x<m && y<n){
                        if(board[x][y]==1) cnt++;
                    }
                }
                if(board[i][j]==1){
                    if(cnt<2 || cnt>3){
                        grid[i][j]=0;
                    }
                }
                else {
                    if(cnt==3){
                        grid[i][j]=1;
                    }
                }
            }
        }
        board=grid;
    }
};