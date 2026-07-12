class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int cnt=1;
        int prev=1e9+1;
        while(!pq.empty()){
            auto [val,i]=pq.top();pq.pop();
            if(val==prev){
                arr[i]=cnt-1;
            }
            else {
                prev=val;
                arr[i]=cnt;
                cnt++;
            }  
        }
        return arr;
    }
};