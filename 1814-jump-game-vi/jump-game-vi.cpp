class Solution {
public:

int maxResult(vector<int>& nums, int k) {
	vector<int> dp(size(nums));
	dp[0] = nums[0];
	deque<int> q{ 0 };
	for(int i = 1; i < size(nums); i++) {
		if(q.front() < i - k) q.pop_front();    
		dp[i] = nums[i] + dp[q.front()];
		while(!q.empty() && dp[q.back()] <= dp[i])
		    q.pop_back();
		q.push_back(i);
	}
	return dp.back();
}
    long long help(int ind,vector<int>& nums, int k,vector<int>& dp){
        int n=nums.size();
        if(ind==n-1) return nums[n-1];
        if(dp[ind]!=-1) return dp[ind];
        long long ans=INT_MIN;
        for(int i=1;i<=k;i++){
            if(ind+i>=n) break;
            long long temp=nums[ind]+help(ind+i,nums,k,dp);
            ans=max(ans,temp);
        }
        return dp[ind]=ans;
    }
    int maxResult2(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return help(0,nums,k,dp);
    }
    int maxResult3(vector<int>& nums, int k){
        int n=nums.size();
        vector<int> dp(n,-1); 
        dp[n-1]=nums[n-1];
        for(int ind=n-2;ind>=0;ind--){
            long long ans=INT_MIN;
            for(int i=1;i<=k;i++){
                if(ind+i>=n) break;
                long long temp=nums[ind]+dp[ind+i];
                ans=max(ans,temp);
            }
            dp[ind]=ans;
        }
        return dp[0];
    }
};