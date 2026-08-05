class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans=0;
        int dec=0;
        for(int i:batteryPercentages){
            if(i-dec<=0) continue;
            ans++;
            dec++;
        }
        return ans;
    }
};