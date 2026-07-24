class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a=str1.length();
        int b=str2.length();
        int n=gcd(a,b);
        int cnt=0;
        string ans=str1.substr(0,n);
        if(str1+str2==str2+str1) return ans;
        return "";
    }
};