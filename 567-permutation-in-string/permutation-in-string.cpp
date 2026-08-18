class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mpp1(26,0);
        vector<int> mpp2(26,0);
        for(char c:s1) mpp1[c-'a']++;
        int l=0;
        int n=s2.length();
        for(int r=0;r<n;r++){
            mpp2[s2[r]-'a']++;
            while(mpp2[s2[r]-'a']>mpp1[s2[r]-'a']){
                mpp2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==s1.length()) return true;
        }
        return false;
    }
};