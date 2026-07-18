class Solution {
public:
    int characterReplacement(string s, int k) {
        // [ACAAB] _ _ _ _  k=2
        // vector<int> mpp(26,0);
        // len - maxf <=k
        // maxl=max(maxl,len);
        // 5 - 3 = 2
        vector<int> mpp(26,0);
        int n=s.length();
        int l=0;
        int maxl=0;
        int maxf=0;
        for(int r=0;r<n;r++){
            mpp[s[r]-'A']++;
            maxf=max(maxf,mpp[s[r]-'A']);
            int len=r-l+1;
            while((r-l+1)-maxf>k){
                mpp[s[l]-'A']--;
                l++;
                maxf=0;
                for(int i:mpp) maxf=max(maxf,i);
            }
            maxl=max(maxl,r-l+1);
        }
        return maxl;
      }
};