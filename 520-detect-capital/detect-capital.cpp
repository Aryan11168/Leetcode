class Solution {
public:
    bool detectCapitalUse(string s) {
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z') cnt++;
        }
        if(cnt==n || cnt==0) return true;
        else if(cnt==1 && (s[0]>='A' && s[0]<='Z')) return true;
        return false;
    }
};