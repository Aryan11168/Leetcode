class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> row(m,INT_MAX);
        vector<int> col(n,INT_MIN);
        for(int i=0;i<m;i++){
            int ans=INT_MAX;
            for(int j=0;j<n;j++){
                ans=min(ans,matrix[i][j]);
            }
            row[i]=ans;
        }
        for(int i=0;i<n;i++){
            int ans=INT_MIN;
            for(int j=0;j<m;j++){
                ans=max(ans,matrix[j][i]);
            }
            col[i]=ans;
        }
        vector<int> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==row[i] && matrix[i][j]==col[j]){
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;

    }
};