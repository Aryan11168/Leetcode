class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
            }
            else ans=max(ans,nums[i]-mini);
        }
        return ans==0?-1:ans; 
    }
};