class Solution {
public:
    void help(unordered_map<int,int>& mpp,vector<int> temp,vector<vector<int>>& ans,int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(auto it:mpp){
            if(it.second>0){
                temp.push_back(it.first);
                mpp[it.first]--;
                help(mpp,temp,ans,n);
                temp.pop_back();
                mpp[it.first]++;
            }
        }
        return;

    }
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        unordered_map<int,int> mpp;
        for(int i:nums) mpp[i]++;
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> temp;
        help(mpp,temp,ans,n);
        return ans;
    }
};