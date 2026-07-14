class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi=nums[0];
        for(int i:nums) maxi=max(maxi,i);
        int t[n+1][maxi+1][maxi+1];
        for(int first=0;first<=maxi;first++){
            for(int second=0;second<=maxi;second++){
                bool bothNotEmpty=(first!=0 && second!=0);
                bool gcdMatch=(first==second);
                t[n][first][second]=(bothNotEmpty && gcdMatch)?1:0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int first=0;first<=maxi;first++){
                for(int second=0;second<=maxi;second++){
                    int skip=t[i+1][first][second];
                    int take1=t[i+1][gcd(first,nums[i])][second];
                    int take2=t[i+1][first][gcd(nums[i],second)];
                    t[i][first][second]=(0LL+skip+take1+take2)%MOD;
                }
            }
        }
        return t[0][0][0];
    }
};