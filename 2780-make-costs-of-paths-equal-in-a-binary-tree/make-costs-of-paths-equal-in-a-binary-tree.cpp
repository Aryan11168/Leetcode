class Solution {
public:
    int ans;
    int help(int node,int& n,vector<int>& cost){
        if(node>=n) return 0;
        int lsum=help(2*node+1,n,cost);
        int rsum=help(2*node+2,n,cost);
        ans+=abs(lsum-rsum);
        return cost[node]+max(lsum,rsum);
    }
    int minIncrements(int n, vector<int>& cost) {
        ans=0;
        help(0,n,cost);
        return ans;
    }
};