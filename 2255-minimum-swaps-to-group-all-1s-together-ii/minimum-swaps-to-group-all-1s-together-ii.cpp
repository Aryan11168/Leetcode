class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i:nums){
            if(i==1) cnt++;
        }
        if(cnt<=1) return 0;
        int l=0;
        int r=cnt-1;
        int curr=0;
        
        for(int i=l;i<=r;i++){
            if(nums[i]==1) curr++;
        }
        int ans=min(cnt,cnt-curr);
        for (int i = 1; i < n; i++) {
            if (nums[l] == 1) curr--;
            l++;

            r = (r + 1) % n;
            if (nums[r] == 1) curr++;

            ans = min(ans, cnt - curr);
        }
        return ans;
    }
};