class Solution {
public:

int orangesRotting(vector<vector<int>>& grid) {
    int cnt=0;
    queue<pair<int,int>> q;
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int m=grid.size();
    int n=grid[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    while(!q.empty()){
        int s=q.size();
        cnt++;
        while(s--){
            auto [x,y]=q.front();q.pop();
            for(auto v:dirs){
                int a=x+v[0];
                int b=y+v[1];
                if(a>=0 && a<m && b>=0 && b<n && grid[a][b]==1){
                    grid[a][b]=2;
                    q.push({a,b});
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    return cnt==0?0:cnt-1;
}

};