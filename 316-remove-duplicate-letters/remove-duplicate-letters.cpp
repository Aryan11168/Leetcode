class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        stack<char> st;
        vector<int> mark(26,0);
        for (char c : s){
            freq[c-'a']--;
            if(mark[c-'a']) continue;
            while(!st.empty() && c<st.top() && freq[st.top()-'a']>0){
                mark[st.top()-'a']=0;
                st.pop();
            }
            st.push(c);
            mark[c-'a']=1;
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};