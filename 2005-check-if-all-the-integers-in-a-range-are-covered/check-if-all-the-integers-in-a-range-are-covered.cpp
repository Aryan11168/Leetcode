class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(),ranges.end());
        for(auto& v:ranges){
            int s=v[0];
            int e=v[1];
            if(s>left) break;
            else if(s==left) left=e+1;
            else {
                if(e>=left) left=e+1;
            }
        }
        return left>right;
    }
};