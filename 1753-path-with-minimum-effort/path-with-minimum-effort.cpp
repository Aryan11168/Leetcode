class Solution {
public:
int minimumEffortPath(vector<vector<int>>& heights){
    int m=heights.size();
    int n=heights[0].size();
    if(m==0 || n==0 || (m==n && m==1)) return 0;
    vector<vector<int>> vis(m,vector<int> (n,INT_MAX));
    vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    vis[0][0]=0;
    q.push({0,0,0});
    while(!q.empty()){
        auto [eff,i,j]=q.top();q.pop();
        for(auto it:dirs){
            int a=i+it[0];
            int b=j+it[1];
            if(a>=0 && a<m && b>=0 && b<n){
                int effort=abs(heights[i][j]-heights[a][b]);
                effort=max(eff,effort);
                if(effort<vis[a][b]){
                    q.push({effort,a,b});
                    vis[a][b]=effort;
                }
            }
        }
    }
    return vis[m-1][n-1]; 
}
};