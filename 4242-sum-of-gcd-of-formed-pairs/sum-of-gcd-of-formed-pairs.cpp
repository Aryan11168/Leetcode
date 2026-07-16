class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pregcd(n);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pregcd[i]=gcd(nums[i],maxi);
        }
        sort(pregcd.begin(),pregcd.end());
        long long ans=0;
        for(int i=0;i<n/2;i++){
            ans+=gcd(pregcd[i],pregcd[n-i-1]);
        }
        return ans;
    }
};