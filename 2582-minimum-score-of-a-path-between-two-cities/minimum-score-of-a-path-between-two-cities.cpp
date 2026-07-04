class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        if(n==1) return 0;
        queue<int> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto vec:roads){
            int u=vec[0];
            int v=vec[1];
            int dist=vec[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        pq.push(1);
        int mini=INT_MAX;
        vector<int> vis(n+1,0);
        vis[1]=1;
        while(!pq.empty()){
            auto u=pq.front();pq.pop();
            for(auto [v,l]:adj[u]){
                if(vis[v]) continue;
                pq.push(v);
                vis[v]=1;
            }
        }
        int ans=INT_MAX;
        for(auto vec:roads){
            int u=vec[0];
            int v=vec[1];
            int dist=vec[2];
            if(vis[u] && vis[v]) ans=min(ans,dist);
        }
        return ans;
    }
};