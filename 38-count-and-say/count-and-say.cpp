class Solution {
public:
    string rle(string s) {
        string res = "";
        int count = 1;
        for (int i = 0; i < s.length()-1; i ++) {
            if (s[i] == s[i+1]) {
                count++;
            } else {
                res += (count + '0');
                res += s[i];
                count = 1;
            }

        }
        res += (count + '0');
        res += s[s.length()-1];
        return res;
    }
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        return rle(countAndSay(n-1));
    }
};