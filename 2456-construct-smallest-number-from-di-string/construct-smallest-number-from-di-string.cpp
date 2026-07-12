class Solution {
public:
    void help(int ind,string temp,string& pattern,string& ans,vector<int>& mark){
        int cur=temp.back()-'0';
        if(ind==pattern.length()){
            if(temp.length()==pattern.length()+1){
                ans=min(ans,temp);
                return;
            }
        }
        if(pattern[ind]=='I'){
            for(int i=cur+1;i<=9;i++){
                if(mark[i]) continue;
                mark[i]=1;
                temp+=to_string(i);
                help(ind+1,temp,pattern,ans,mark);
                mark[i]=0;
                temp.pop_back();
            }
        }
        else {
            for(int i=1;i<cur;i++){
                if(mark[i]) continue;
                mark[i]=1;
                temp+=to_string(i);
                help(ind+1,temp,pattern,ans,mark);
                mark[i]=0;
                temp.pop_back();
            }
        }
        return;

    }
    string smallestNumber(string pattern) {
        vector<int> mark(10,0);
        string ans="9999999999";
        string temp="";
        int n=pattern.length();
        for(int i=1;i<=9;i++){
            mark[i]=1;
            temp+=to_string(i);
            help(0,temp,pattern,ans,mark);
            mark[i]=0;
            temp.pop_back();
        }
        return ans;
    }
};