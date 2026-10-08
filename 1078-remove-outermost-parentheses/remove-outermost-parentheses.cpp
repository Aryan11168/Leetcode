class Solution {
public:

string removeOuterParentheses(string s){
    stack<char> st;
    string ans="";
    for(char c:s){
        if(st.empty()){
            st.push(c);
            continue;
        }
        if(c=='('){
            st.push(c);
            ans+=c;
        }
        else {
            st.pop();
            if(!st.empty()) ans+=c;
        }
    }
    return ans;
}

};