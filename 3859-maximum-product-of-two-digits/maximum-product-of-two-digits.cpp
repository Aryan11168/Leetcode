class Solution {
public:
    int maxProduct(int n) {
       vector<int> mark(10,0);
       while(n>0){
        mark[n%10]++;
        n/=10;
       }
       int ans=1;
       int cnt=0;
       for(int i=9;i>=0;i--){
        if(cnt==2) return ans;
        if(mark[i]>0){
            ans*=i;
            mark[i]--;
            cnt++;
        }
        if(cnt<2 && mark[i]>0){
            ans*=i;
            mark[i]--;
            cnt++;
        }
       }
        return 0;
    }
};