class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0;
        int r=0;
        int curr=0;
        int sum=INT_MIN;
        for(int i =0; i<=nums.size()-1; i++){
            curr+=nums[i];
            while(curr<0){
                curr-=nums[l];
                l++;
            }
            sum=max(sum,curr);
        }
        if(sum==0){
            return *max_element(nums.begin(), nums.end());
        }
        return sum;
    }
};