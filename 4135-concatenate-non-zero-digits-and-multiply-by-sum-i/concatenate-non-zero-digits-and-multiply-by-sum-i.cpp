class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long x=0;
        string s=to_string(n);
        string temp="";
        for(char c:s){
            if(c!='0'){
                temp.push_back(c);
                sum+=c-'0';
            }
        }
        if(temp.length()==0) return 0;
        x=stoll(temp);
        return x*sum;
    }
};