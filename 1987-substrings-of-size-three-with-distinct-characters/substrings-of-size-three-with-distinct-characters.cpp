class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.length();
        if(n<=2) return 0;
        unordered_map<char,int> st;
        int i=0;
        st[s[i]]++;
        st[s[i+1]]++;
        st[s[i+2]]++;
        int cnt=0;
        for(i=3;i<n;i++){
            if(st.size()==3) cnt++;
            st[s[i]]++;
            st[s[i-3]]--;
            if(st[s[i-3]]==0) st.erase(s[i-3]);
        }
        if(st.size()==3) cnt++;
        return cnt;
    }
};