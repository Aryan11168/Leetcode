class Solution {
public:

void solve(vector<vector<char>>& board){
    int m=board.size();
    int n=board[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        if(board[i][0]=='O') q.push({i,0});
        if(board[i][n-1]=='O') q.push({i,n-1});
    }
    for(int i=0;i<n;i++){
        if(board[0][i]=='O') q.push({0,i});
        if(board[m-1][i]=='O') q.push({m-1,i});
    }
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        board[x][y]='#';
        for(auto v:dirs){
            int a=x+v[0];
            int b=y+v[1];
            if(a>=0 && a<m && b>=0 && b<n && board[a][b]=='O'){
                q.push({a,b});
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='#') board[i][j]='O';
        }
    }
    return;
}

};