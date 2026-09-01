class Solution {
public:
    int minOperations(int n) {
        string s=bitset<32>(n).to_string();
        int cnt=0;
        int op=0;
        for(int i=31;i>=0;i--){
            if(s[i]=='1') cnt++;
            else {
                if(cnt==1){
                    op++;
                    cnt=0;
                }
                else if(cnt==0){
                    continue;
                }
                else{
                    op++;
                    cnt=1;
                }
            }
        }
        if(cnt==1) op++;
        else if(cnt>=2){
            op+=2;
        }
        return op;
    }
};