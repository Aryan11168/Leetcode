class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxc=0;
        int ans=INT_MAX;
        int n=nums.size();
        int m=divisors.size();
        for(int i=0;i<m;i++){
            int a=divisors[i];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[j]%a==0) cnt++;
            }
            if(cnt>maxc){
                maxc=cnt;
                ans=a;
            }
            else if(cnt==maxc) ans=min(ans,a);
        }
        return ans;
    }
};