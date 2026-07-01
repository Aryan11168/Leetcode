class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> mark(n,vector<int>(n,0));
        pq.push({1,0,0});
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!pq.empty()){
            auto [path,x,y]=pq.top();pq.pop();
            if(mark[x][y]) continue;
            if(x==n-1 && y==n-1) return path;
            mark[x][y]=1;
            for(auto v:dirs){
                int a=x+v[0];
                int b=y+v[1];
                if(min(a,b)>=0 && max(a,b)<n && !mark[a][b] && grid[a][b]!=1){
                    pq.push({path+1,a,b});
                }
            }
        }
        return -1;
    }
};