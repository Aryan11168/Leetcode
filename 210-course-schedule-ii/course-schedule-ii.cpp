class Solution {
public:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> in(numCourses,0);
    vector<int> ans;
    queue<int> q;
    vector<vector<int>> adj(numCourses);
    for(auto it:prerequisites){
        int a=it[0];int b=it[1];
        adj[b].push_back(a);
    }  
    for(int i=0;i<adj.size();i++){
        for(auto it:adj[i]){
            in[it]++;
        }
    }
    for(int i=0;i<numCourses;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();q.pop();
        for(auto it:adj[node]){
            in[it]--;
            if(in[it]==0) q.push(it);
        }
        ans.push_back(node);
    }
    for(int i:in){
        if(i!=0) return {};
    }
    return ans;
}
};