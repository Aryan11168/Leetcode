class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> adj;
        for(int i=0;i<n;i++){
            adj.push_back({nums[i],i});
        }
        sort(adj.begin(),adj.end());
        int mark=1;
        vector<int> vis(n,-1);
        vis[0]=1;
        for(int i=1;i<n;i++){
            if(abs(nums[i-1]-nums[i])<=maxDiff){
                vis[i]=mark;
            }
            else {
                vis[i]=mark+1;
                mark++;
            }
        }
        int s=queries.size();
        vector<bool> ans;
        for(int i=0;i<s;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(vis[u]==vis[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};