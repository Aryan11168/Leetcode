class Solution {
public:
void permuteHelper(vector<int> &nums, vector<int> &mark, vector<int> &temp, vector<vector<int>> &ans) {
    if (temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            temp.push_back(nums[i]);

            permuteHelper(nums, mark, temp, ans);

            // backtrack
            temp.pop_back();
            mark[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> mark(nums.size(), 0), temp;
    permuteHelper(nums, mark, temp, ans);
    return ans;
}

};