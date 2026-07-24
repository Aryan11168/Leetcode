class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        while (l < n && nums[l] != 0)
            l++;
        for (int i = l + 1; i < n; i++) {
            if (nums[i] != 0)
                swap(nums[l], nums[i]);
            while (l < n && nums[l] != 0)
                l++;
        }
    }
};