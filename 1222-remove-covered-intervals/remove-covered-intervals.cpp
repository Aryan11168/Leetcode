class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int s=intervals[0][0];
        int e=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            int ns=intervals[i][0];
            int ne=intervals[i][1];
            if(ns>=e || (ne>e && s<ns)){
                cnt++;
                s=ns;
                e=ne;
            }

            else if(ns<=e){
                e=max(e,ne);
            }
        }
        return cnt+1;
    }
};