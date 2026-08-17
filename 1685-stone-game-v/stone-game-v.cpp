class Solution {
public:
    int help(int l,int r,int sum,vector<int>& stoneValue,vector<vector<int>>& dp){
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        int m=l;
        int curr=0;
        for(int m=l;m<r;m++){
            curr+=stoneValue[m];
            int front=sum-curr;
            if(curr<front){
                ans=max(ans,curr+help(l,m,curr,stoneValue,dp));
            }
            else if(curr>front){
                ans=max(ans,front+help(m+1,r,front,stoneValue,dp));
            }
            else {
                ans=max(ans,curr+max(help(l,m,curr,stoneValue,dp),help(m+1,r,curr,stoneValue,dp)));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int sum=0;
        int n=stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) sum+=stoneValue[i];
        return help(0,n-1,sum,stoneValue,dp);
    }
};