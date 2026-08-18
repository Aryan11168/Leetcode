class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mpp;
        for(auto v:trips){
            mpp[v[1]]+=v[0];
            mpp[v[2]]-=v[0];
        }
        for(auto it:mpp){
            if((capacity-=it.second)<0) return false;
        }
        return true;
    }
};