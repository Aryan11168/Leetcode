class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length();
        int l=0,r=n-1;
        while(l<r){
            while(l<r && (string("aeiouAEIOU").find(s[l]) == string::npos)) l++;
            while(r>l && (string("aeiouAEIOU").find(s[r]) == string::npos)) r--;
            if(l>=r) break;
            swap(s[l],s[r]);
            l++;r--;
        }
        return s;
    }
};