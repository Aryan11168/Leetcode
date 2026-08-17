class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxl=0;
        int n=nums.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            int ind=i;
            if(dp[ind]!=-1){
                continue;
            }
            while(dp[ind]==-1 && st.find(ind)==st.end()){
                st.insert(ind);
                ind=nums[ind];
            }
            int len;
            if(dp[ind]!=-1){
                len=(int)st.size()+dp[ind];
            }
            else len=(int) st.size();
            for(int x:st) dp[x]=len;
            maxl=max(maxl,len);
        }
        return maxl;
    }
};