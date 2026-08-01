class Solution {
public:
    int help(int l,int r,vector<int>& nums,vector<vector<int>>& dp){
        if(l==r) return nums[l];
        if(dp[l][r]!=INT_MIN) return dp[l][r];
        int right=nums[r]-help(l,r-1,nums,dp);
        int left=nums[l]-help(l+1,r,nums,dp);
        return dp[l][r]=max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        int r=n-1;
        int l=0;
        return help(l,r,nums,dp)>=0;
    }
};