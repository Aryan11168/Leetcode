class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxl=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==-1) continue;
            int ind=i;
            int len=0;
            while(nums[ind]!=-1){
                int next=nums[ind];
                nums[ind]=-1;
                ind=next;
                len++;
            }
            maxl=max(maxl,len);
        }
        return maxl;
    }
};