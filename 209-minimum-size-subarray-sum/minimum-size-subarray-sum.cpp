class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int minlen=INT_MAX;
        int curr=0;
        for(int r=0;r<n;r++){
            curr+=nums[r];
            while(curr>=target){
                minlen=min(minlen,r-l+1);
                curr-=nums[l];
                l++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};