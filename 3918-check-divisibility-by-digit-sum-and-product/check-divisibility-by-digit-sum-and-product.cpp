class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int t=n;
        while(n>0){
            int a=n%10;
            n/=10;
            sum+=a;
            pro*=a;
        }
        return t%(sum+pro)==0;
    }
};