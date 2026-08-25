class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int a=k;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]<a) continue;
            else if(nums[i]==a){
                a+=k;
            }
            else return a;
        }
        return a;
    }
};