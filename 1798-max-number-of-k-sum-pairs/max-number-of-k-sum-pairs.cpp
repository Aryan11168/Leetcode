class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=k-nums[i];
            if(mpp.count(a) && mpp[a]>0){
                cnt++;
                mpp[a]--;
            }
            else mpp[nums[i]]++;
        }
        return cnt;
    }
};