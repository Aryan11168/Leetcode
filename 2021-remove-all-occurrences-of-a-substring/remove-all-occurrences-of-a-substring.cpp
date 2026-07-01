class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=part.length();
        while(s.find(part)!=string::npos){
            int ind=s.find(part);
            s.erase(ind,n);
        }
        return s;
    }
};