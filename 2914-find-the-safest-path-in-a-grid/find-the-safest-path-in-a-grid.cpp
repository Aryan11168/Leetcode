class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        vector<vector<int>> safe(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                q.push({i,j});
                safe[i][j]=0;
            }
        }
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [x,y]=q.front();q.pop();
                for(auto v:dirs){
                    int a=x+v[0];
                    int b=y+v[1];
                    if(min(a,b)>=0 && max(a,b)<n && safe[a][b]==-1){
                        safe[a][b]=safe[x][y]+1;
                        q.push({a,b});
                    }
                }
            }
        }
        priority_queue<tuple<int,int,int>> pq;
        pq.push({safe[0][0],0,0});
        vector<vector<int>> vis(n,vector<int>(n,0));
        while(!pq.empty()){
            auto [dist,x,y]=pq.top();pq.pop();
            if(x==n-1 && y==n-1) return dist;
            if(vis[x][y]) continue;
            vis[x][y]=1;
            for(auto v:dirs){
                int a=x+v[0];
                int b=y+v[1];
                if(min(a,b)>=0 && max(a,b)<n && safe[a][b]!=-1){
                    pq.push({min(dist,safe[a][b]),a,b});
                }
            }
        }
        return 0;

    }
};