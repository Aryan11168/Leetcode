class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n+1);
        for(auto v:edges){
            adj[v[0]].insert(v[1]);
            adj[v[1]].insert(v[0]);
        }
        vector<int> odd;
        for(int i=1;i<=n;i++){
            if(adj[i].size()&1) odd.push_back(i);
        }
        if(odd.size()==0) return true;
        else if(odd.size()>4) return false;
        if(odd.size()==2){
            int u=odd[0];
            int v=odd[1];
            if (adj[u].find(v) == adj[u].end()) return true;
            for (int x = 1; x <=n; x++) {
                if (x == u || x == v)
                    continue;
                if (adj[u].find(x) == adj[u].end() &&
                    adj[v].find(x) == adj[v].end()) {
                    return true;
                }
            }
        }
        else {
            int a=odd[0];
            int b=odd[1];
            int c=odd[2];
            int d=odd[3];
            return (adj[a].find(d) == adj[a].end() && adj[b].find(c) == adj[b].end()) || (adj[a].find(b) == adj[a].end() && adj[c].find(d) == adj[c].end()) ||(adj[a].find(c) == adj[a].end() && adj[b].find(d) == adj[b].end());
        }
        return false;
    }
};