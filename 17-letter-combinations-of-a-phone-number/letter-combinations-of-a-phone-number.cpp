class Solution {
public:
    // 2 3 
    // 2 => a,b,c;
    // a
    // b
    // c
    // 3 => d,e,f;
    // a d
    // b d
    // c d
    // a e
    // b e
    // c e
    // a f
    // b f
    // c f
    void help(int ind,string& curr,string& digits,vector<string>& alpha,vector<string>& ans){
        if(ind==digits.length()){
            ans.push_back(curr);
            return;
        }
        // string a=alpha[ind];
        // ind=0 digits="23" 
        string a=alpha[digits[ind]-'0'];
        for(char c:a){
            curr.push_back(c);
            // help(1,"a",)
            help(ind+1,curr,digits,alpha,ans);
            // curr="a"
            curr.pop_back();
            // curr=""
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0) return ans;
        vector<string>alpha={
            "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curr="";
        help(0,curr,digits,alpha,ans);
        return ans;
    }
};