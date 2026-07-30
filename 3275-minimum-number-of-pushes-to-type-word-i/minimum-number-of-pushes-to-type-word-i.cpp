class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mpp(26,0);
        for(char c:word) mpp[c-'a']++;
        sort(mpp.begin(),mpp.end());
        int cnt=0;
        int ans=0;
        for(int i:mpp){
            if(i==0) continue;
            cnt++;
            if(cnt<=8) ans+=i;
            else if(cnt<=16) ans+=i*2;
            else if(cnt<=24) ans+=i*3;
            else ans+=i*4;
        }
        return ans;
    }
};