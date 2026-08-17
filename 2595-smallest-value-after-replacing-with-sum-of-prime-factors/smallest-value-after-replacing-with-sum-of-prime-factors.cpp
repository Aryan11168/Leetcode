class Solution {
public:
    int getSum(int n){
        int div=2;
        int sum=0;
        while(n>1){
            while(n%div==0){
                sum+=div;
                n/=div;
            }
            div++;
        }
        return sum;
    }
    int smallestValue(int n) {
        while(true){
            int sum=getSum(n);
            if(n==sum) break;
            n=sum;
        }
        return n;
    }
};