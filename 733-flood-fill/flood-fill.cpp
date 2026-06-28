class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int m=image.size();
        int n=image[0].size();
        int given=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(auto v:dirs){
                int a=x+v[0];
                int b=y+v[1];
                if(a>=0 && a<m && b>=0 && b<n && image[a][b]==given && image[a][b]!=color){
                    q.push({a,b});
                    image[a][b]=color;
                }
            }
        }
        return image;
    }
};