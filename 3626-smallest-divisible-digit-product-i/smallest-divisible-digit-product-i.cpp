class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int a=1;
            int temp=n;
            while(temp){
                a=a*(temp%10);
                temp/=10;
                if(a==0) break;
            }
            if(a%t==0) return n;
            n++;
        }
        return 0;
    }
};