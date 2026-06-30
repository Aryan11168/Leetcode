class Solution {
public:
    int findLUSlength(string a, string b) {
        int len=0;
        if(b.find(a)==string::npos){
            int size=a.length();
            len=max(len,size);
        }
        if(a.find(b)==string::npos){
            int size=b.length();
            len=max(len,size);
        }
        return len==0?-1:len;
    }
};