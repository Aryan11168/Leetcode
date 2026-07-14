class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>& nums,int ind,int gcd1,int gcd2,vector<vector<vector<int>>>& dp){
        if(ind==nums.size()){
            if(gcd1 && gcd2 && gcd1==gcd2) return 1;
            return 0;
        }
        if(dp[ind][gcd1][gcd2]!=-1) return dp[ind][gcd1][gcd2];
        int skip=solve(nums,ind+1,gcd1,gcd2,dp);
        int seq1=solve(nums,ind+1,__gcd(gcd1,nums[ind]),gcd2,dp);
        int seq2=solve(nums,ind+1,gcd1,__gcd(gcd2,nums[ind]),dp);
        return dp[ind][gcd1][gcd2]=(0LL+skip+seq1+seq2)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i:nums) maxi=max(maxi,i);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));
        return solve(nums,0,0,0,dp);
    }
};