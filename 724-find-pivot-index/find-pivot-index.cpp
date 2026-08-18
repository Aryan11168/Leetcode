class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot=0;
        for(int i:nums) tot+=i;
        int curr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(curr==tot-nums[i]-curr) return i;
            curr+=nums[i];
        }
        return -1;
    }
};