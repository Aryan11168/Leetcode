class Solution {
public:
    // 2 3 
    // 2 => a,b,c;
    // a
    // b
    // c
    // 3 => d,e,f;
    // a
    // b
    // c
    
    void f(int ind,string &digits,vector<string>&alpha,vector<string>&ans,string curr){
        if(digits.empty()) return;
        if(ind== digits.size())
        {
            ans.push_back(curr);
            return;
        }
         string letters= alpha[digits[ind]-'0'];

        for(char ch: letters){
            curr.push_back(ch);              // choose
            f(ind+1, digits, alpha,ans, curr); // explore
            curr.pop_back();                 // backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>alpha={
            "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        string curr="";
        f(0,digits, alpha,ans, curr);
        return ans;
    }
};