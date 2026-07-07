class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;

        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost=abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push({cost,i,j});
            }
        }
        DSU dsu(n);
        int ans = 0;
        int cnt = 0;
        while(!pq.empty() && cnt < n-1){
            auto [c, u, v] = pq.top(); pq.pop();
            if(dsu.find(u) != dsu.find(v)){
                dsu.unite(u, v);
                ans += c;
                cnt++;
            }
        }
        return ans;
    }
};