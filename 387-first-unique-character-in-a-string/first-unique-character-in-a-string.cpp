class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26,0);
        for(char c:s) f[c-'a']++;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(f[c-'a']==1) return i;
        }
        return -1;
    }
};