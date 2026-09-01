class Solution {
public:
    int hIndex(vector<int>& nums) {
        int ans=0;
        int l=1;
        int h=nums.size();
        while(l<=h){
            int m=l+(h-l)/2;
            int cnt=0;
            for(int i:nums){
                if(i>=m) cnt++;
            }
            if(cnt>=m){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};