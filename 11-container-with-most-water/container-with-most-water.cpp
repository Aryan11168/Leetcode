class Solution {
public:
    int maxArea(vector<int>& nums) {
        long long maxi=0;
        int l=0,r=nums.size()-1;
        while(l<r){
            long long water=(r-l)*(min(nums[r],nums[l]));
            maxi=max(maxi,water);
            if(nums[l]<=nums[r]) l++;
            else r--;
        }
        return maxi;

    }
};