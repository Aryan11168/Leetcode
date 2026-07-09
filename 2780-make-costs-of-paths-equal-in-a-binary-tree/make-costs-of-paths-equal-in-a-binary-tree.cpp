class Solution {
public:
    int ans;
    int help(int node,int& n,vector<int>& cost){
        if(node>=n) return 0;
        int lsum=help(2*node+1,n,cost);
        int rsum=help(2*node+2,n,cost);
        ans+=abs(lsum-rsum);
        return cost[node]+max(lsum,rsum);
    }
    int minIncrements2(int n, vector<int>& cost) {
        ans=0;
        help(0,n,cost);
        return ans;
    }
    // there is a optimal approach
    int minIncrements(int n, vector<int>& cost) {
        int cnt = 0;

        for (int i = n / 2; i > 0; i--) {
            int left = i * 2;
            int right = i * 2 + 1;
          
            cnt += abs(cost[left - 1] - cost[right - 1]);

            cost[i - 1] += max(cost[left- 1], cost[right- 1]);
        }
      
        return cnt;
    }
};