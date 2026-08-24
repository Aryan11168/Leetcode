class Solution {
public:
    int help(int ind,vector<int>& nums, int target,vector<int>& dp){
        int n=nums.size();
        if(ind==n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=0;
        for(int i=ind+1;i<n;i++){
            if(abs(nums[i]-nums[ind])<=target){
                ans=max(ans,1+help(i,nums,target,dp));
            }
        }
        return dp[ind]=(ans==0?INT_MIN:ans);
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=help(0,nums,target,dp);
        if(ans<=0) return -1;
        return ans;
    }
};