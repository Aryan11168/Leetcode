class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto& v:bookings){
            int s=v[0];
            int e=v[1];
            int add=v[2];
            for(int i=s;i<=e;i++){
                ans[i-1]+=add;
            }
        }
        return ans;
    }
};