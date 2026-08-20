class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int l1=nums[0];
        int l2=nums[1];
        for(int i=2;i<n;i++){
            if(l1>l2){
                l1=nums[i];
                arr1.push_back(nums[i]);
            }
            else {
                l2=nums[i];
                arr2.push_back(nums[i]);
            }
        }
        for(int i:arr2) arr1.push_back(i);
        return arr1;
    }
};