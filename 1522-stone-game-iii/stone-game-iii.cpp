class Solution {
public:
    int help(int ind,vector<int>& stoneValue,vector<int>& dp){
        int n=stoneValue.size();
        if(ind==n) return 0;
        if(dp[ind]!=INT_MIN) return dp[ind];
        int one=stoneValue[ind]-help(ind+1,stoneValue,dp);
        int two=INT_MIN;
        int three=INT_MIN;
        if(ind+1<n) two=stoneValue[ind]+stoneValue[ind+1]-help(ind+2,stoneValue,dp);
        if(ind+2<n) three=stoneValue[ind]+stoneValue[ind+1]+stoneValue[ind+2]-help(ind+3,stoneValue,dp);
        return dp[ind]=max(one,max(two,three));

    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,INT_MIN);
        int ans=help(0,stoneValue,dp);
        if(ans==0) return "Tie";
        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "";
    }
};