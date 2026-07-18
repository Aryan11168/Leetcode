class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int sm=nums[0];
        int lar=nums[0];
        for(int i=1;i<n;i++){
            sm=min(sm,nums[i]);
            lar=max(lar,nums[i]);
        }
        return gcd(sm,lar);
    }
};