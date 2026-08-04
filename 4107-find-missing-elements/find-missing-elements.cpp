class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=nums[0];
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(s==nums[i]){
                s++;
            }
            else {
                while(s!=nums[i]){
                    ans.push_back(s);
                    s++;
                }
                s++;
            }
        }
        return ans;
    }
};