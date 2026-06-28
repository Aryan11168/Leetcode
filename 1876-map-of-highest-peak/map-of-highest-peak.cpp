class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(m,vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(auto v:dirs){
            int a=x+v[0];
            int b=y+v[1];
            if(a>=0 && a<m && b>=0 && b<n && dist[a][b]==-1){
                dist[a][b]=dist[x][y]+1;
                q.push({a,b});
            }
        }
    }
    return dist;
    }
};