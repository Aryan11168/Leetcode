class Solution {
public:
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<int> inDeg(n,0);
    vector<vector<int>> adj(n);
    int cnt=0;
    for(auto v:prerequisites){
        adj[v[1]].push_back(v[0]);
    }
    for(int i=0;i<n;i++){
        for(int j:adj[i]) inDeg[j]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();q.pop();
        cnt++;
        for(int i:adj[node]){
            inDeg[i]--;
            if(inDeg[i]==0) q.push(i);
        }
    }
    return cnt==n;
}
};