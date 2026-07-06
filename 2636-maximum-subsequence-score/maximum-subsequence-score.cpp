class Solution {
public:
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        long long curr=0;
        for(int i=0;i<k-1;i++){
            curr+=vec[i].second;
            pq.push(vec[i].second);
        }
        for(int i=k-1;i<n;i++){
            long long mn=vec[i].first;
            long long sum=vec[i].second;
            if(pq.size()>k-1){
                curr-=pq.top();
                pq.pop();
            }
            curr+=sum;
            pq.push(sum);
            ans=max(ans,mn*curr);
        }
        return ans;
    }
};