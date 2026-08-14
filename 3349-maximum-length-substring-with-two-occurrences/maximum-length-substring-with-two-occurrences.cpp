class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int maxl=-1;
        for(int i=0;i<n;i++){
            vector<int> mpp(26,0);
            bool is=true;
            for(int j=i;j<n;j++){
                mpp[s[j]-'a']++;
                if(mpp[s[j]-'a']>2){
                    break;
                }
                maxl=max(maxl,j-i+1);
            }
        }
        return maxl;
    }
};