class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1 ||k==n) return 0;
        vector<int> vec;
        for(int i=0;i<n-1;i++){
            vec.push_back(nums[i]+nums[i+1]);
        }
        int s=vec.size();
        sort(vec.begin(),vec.end());
        long long maxi=nums[0]+nums[n-1];
        long long mini=nums[0]+nums[n-1];
        for(int i=0;i<k-1;i++){
            mini+=vec[i];
            maxi+=vec[s-1-i];
        }
        return maxi-mini;
    }
};