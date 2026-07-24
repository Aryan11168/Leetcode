class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i:nums) if(i==0) cnt++;
        if(cnt>=2) return vector<int>(n,0);
        long long pro=1;
        if(cnt==1){
            int ind=-1;
            for(int i=0;i<n;i++){
                if(nums[i]==0) ind=i;
                else {
                    pro*=nums[i];
                    nums[i]=0;
                }
            }
            nums[ind]=pro;
            return nums;
        }
        for(int i:nums) pro*=i;
        for(int& i:nums){
            i=pro/i;
        }
        return nums;
    }
};