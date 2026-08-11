class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int> st;
        st[0]=-1;
        long long curr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            curr+=nums[i];
            if(k!=0) curr=curr%k;
            if(st.find(curr)!=st.end()){
                if(i-st[curr]>1) return true;
            }
            else {
                st[curr]=i;
            }
        }
        return false;
    }
};