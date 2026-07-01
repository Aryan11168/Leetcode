class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int minj=INT_MAX;
        int maxj=INT_MIN;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) continue;
                mini=min(mini,i);
                maxi=max(maxi,i);
                minj=min(minj,j);
                maxj=max(maxj,j);
            }
        }
        if(mini==INT_MAX) return 0;
        return (maxi-mini+1)*(maxj-minj+1);
    }
};