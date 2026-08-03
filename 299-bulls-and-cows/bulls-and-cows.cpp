class Solution {
public:
    string getHint(string s, string g) {
        int bulls=0;
        int cows=0;
        int n=s.length();
        vector<int> mpp(10,0);
        for(int i=0;i<n;i++){
            if(s[i]==g[i]){
                bulls++;
                g[i]='#';
            }
            else mpp[s[i]-'0']++;
        }
        for(int i=0;i<n;i++){
            if(g[i]=='#') continue;
            if(mpp[g[i]-'0']>0){
                mpp[g[i]-'0']--;
                cows++;
            }
        }
        string ans="";
        ans=ans+to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};