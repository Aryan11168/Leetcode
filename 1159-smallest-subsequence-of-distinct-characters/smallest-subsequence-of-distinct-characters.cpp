class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        stack<char> st;
        vector<int> mark(26,0);
        for(char c:s){
            freq[c-'a']--;
            if(mark[c-'a']) continue;
            if(st.empty() || st.top()<c || (st.top()>c && freq[st.top()-'a']==0)){
                mark[c-'a']=1;
                st.push(c);
            }
            else {
                while(!st.empty() && st.top()>c && freq[st.top()-'a']>0){
                    mark[st.top()-'a']=0;
                    st.pop();
                }
                st.push(c);
                mark[c-'a']=1;
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};