class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt=0;
        int n=costs.size();
        sort(costs.begin(),costs.end());
        for(int i:costs){
            if(coins>=i){
                cnt++;
                coins-=i;
            }
            else break;
        }
        return cnt;
    }
};