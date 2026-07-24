class Solution {
public:

    string reverseWords(string str) {
        int s=0;
        string ans="";
        while(str[s]==' ') s++;
        int n=str.length();
        for(int i=s;i<n;i++){
            if(str[i]==' ' && i>s){
                if(ans.length()==0){
                    ans=str.substr(s,i-s);
                }
                else ans=str.substr(s,i-s)+" " + ans;
                s=i+1;
                while(s<n && str[s]==' ') s++;
            }
        }
        if(s<n && str[s]!=' '){
            if(ans.length()==0){
                ans=str.substr(s,n-s);
            }
            else ans=str.substr(s,n-s)+" " + ans;
        }
        return ans;
    }
};