class Solution {
public:
    int minOperations(int n) {
        string s= bitset<32>(n).to_string();
        int count=0;
        int op=0;
        for(int i= 31; i>=0; i--){
           if(s[i]=='1')count++;
           else{
             if(count==0) continue;
             else if(count==1) {
                op+=1;
                count=0;
             }
             else{
                op++;
                count=1;
             }
           }
        }
        if(count!=0){
            if(count==1) op++;
            else{
                op+=2;
            }
        }
        return op;
    }
};