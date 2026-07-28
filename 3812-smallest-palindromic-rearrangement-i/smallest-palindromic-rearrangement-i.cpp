class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        string sor;
        for(int i=0;i<n/2;i++){
            sor.push_back(s[i]);
        }
        sort(sor.begin(),sor.end());
        for(int i=0;i<n/2;i++){
            s[i]=sor[i];
            s[n-i-1]=sor[i];
        }
        return s;
    }
};