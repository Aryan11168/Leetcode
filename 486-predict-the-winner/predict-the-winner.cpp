class Solution {
public:
    int help(int l,int r,vector<int>& nums){
        if(l==r) return nums[l];
        int right=nums[r]-help(l,r-1,nums);
        int left=nums[l]-help(l+1,r,nums);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int r=nums.size()-1;
        int l=0;
        return help(l,r,nums)>=0;
    }
};