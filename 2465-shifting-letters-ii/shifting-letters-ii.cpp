class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> diff(n,0);
        for(auto shift:shifts){
            if(shift[2]==1){
                diff[shift[0]]++;
                if(shift[1]+1<n){
                    diff[shift[1]+1]--;
                }
            }
            else {
                diff[shift[0]]--;
                if(shift[1]+1<n){
                    diff[shift[1]+1]++;
                }
            }
        }
        string res(n,' ');
        int num=0;
        for(int i=0;i<n;i++){
            num=(num+diff[i])%26;
            if(num<0) num+=26;
            res[i]='a'+(s[i]-'a'+num)%26;
        }
        return res;
    }
};