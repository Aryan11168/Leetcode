class Solution {
public:
    string mergeAlternately(string a, string b) {
        int i=0;
        int j=0;
        string ans="";
        while(i<a.length() && j<b.length()){
            ans.push_back(a[i]);
            ans.push_back(b[j]);
            i++;
            j++;
        }
        while(i<a.length()){
            ans.push_back(a[i]);
            i++;
        }
        while(j<b.length()){
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};