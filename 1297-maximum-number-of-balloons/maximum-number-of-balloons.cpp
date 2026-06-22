class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(5,0);
        for(char c:text){
            if(c=='b') freq[0]++;
            else if(c=='a') freq[1]++;
            else if(c=='l') freq[2]++;
            else if(c=='o') freq[3]++;
            else if(c=='n') freq[4]++;
        }
        int ans=INT_MAX;
        ans=min(ans,freq[0]);
        ans=min(ans,freq[1]);
        ans=min(ans,freq[2]/2);
        ans=min(ans,freq[3]/2);
        ans=min(ans,freq[4]);
        return ans;
    }
};